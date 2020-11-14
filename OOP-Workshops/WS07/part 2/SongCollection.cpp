/* ------------------------------------------------------
Workshop 7: STL Algorithms
Module: SongCollection
Filename: SongCollection.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/10	Completed workshop 7 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "SongCollection.h"

namespace sdds
{
	sdds::SongCollection::SongCollection(const char* filename)
	{
		std::ifstream file(filename);
		std::string line;
		Song song;

		auto removeWhiteSpaces = [](std::string str)
		{
			str.erase(0, str.find_first_not_of(' '));
			str.erase(str.find_last_not_of(' ') + 1);

			return str;
		};

		if (!file)
		{
			std::string error = "Error: [" + std::string(filename) + "] cannot be opened";

			throw error;
		}

		while (std::getline(file, line))
		{
			size_t startPos = 0u;

			song.m_title = removeWhiteSpaces(line.substr(startPos, SIZE_OF_STR_FIELD));

			startPos += SIZE_OF_STR_FIELD;
			song.m_artist = removeWhiteSpaces(line.substr(startPos, SIZE_OF_STR_FIELD));

			startPos += SIZE_OF_STR_FIELD;
			song.m_album = removeWhiteSpaces(line.substr(startPos, SIZE_OF_STR_FIELD));

			startPos += SIZE_OF_STR_FIELD;

			// set the release year of the song to be 0 if the conversion cannot be performed
			try
			{
				song.m_releaseYear = std::stoi((line.substr(startPos, SIZE_OF_NUM_FIELD)));
			}
			catch (std::invalid_argument&)
			{
				song.m_releaseYear = 0u;
			}

			startPos += SIZE_OF_NUM_FIELD;

			// set the length of the song to be 0 if the conversion cannot be performed
			try
			{
				song.m_length = std::stoi((line.substr(startPos, SIZE_OF_NUM_FIELD)));
			}
			catch (std::invalid_argument&)
			{
				song.m_length = 0u;
			}

			startPos += SIZE_OF_NUM_FIELD;

			// set the price of the song to be 0 if the conversion cannot be performed
			try
			{
				song.m_price = std::stod((line.substr(startPos, SIZE_OF_NUM_FIELD)));
			}
			catch (std::invalid_argument&)
			{
				song.m_price = 0.0;
			}
					
			this->songs.push_back(song);
		}

		file.close();
	}

	void SongCollection::display(std::ostream& out) const
	{
		std::for_each(this->songs.begin(), this->songs.end(), [&](const Song& song) { out << song << std::endl; });
		
		size_t totalPlayTime = std::accumulate(this->songs.begin(), this->songs.end(), 0u, [&](size_t total, const Song song) { return total + song.m_length; });

		printbar(out); // using the printbar function defined in the w7_p2 module
		out << "| " << std::setw(76) << "Total Listening Time:" << std::setw(2) << totalPlayTime / 3600u;
		out << ":" << std::setw(2) << std::setfill('0') << totalPlayTime % 3600 / 60;
		out << ":" << std::setw(2) << totalPlayTime % 60 << " |" << std::setfill(' ') << std::endl;
	}

	void SongCollection::sort(const std::string& fieldName)
	{
		if (fieldName == "title")
		{
			std::sort(this->songs.begin(), this->songs.end(), [](const Song& first, const Song& last) { return first.m_title < last.m_title; });
		}
		else if (fieldName == "album")
		{
			std::sort(this->songs.begin(), this->songs.end(), [](const Song& first, const Song& last) { return first.m_album < last.m_album; });
		}
		else if (fieldName == "length")
		{
			std::sort(this->songs.begin(), this->songs.end(), [](const Song& first, const Song& last) { return first.m_length < last.m_length; });
		}
		else
		{
			std::string error = "Error: [" + fieldName + "] is an invalid name of the field";

			throw error;
		}
	}

	void SongCollection::cleanAlbum()
	{		
		auto checkNone = [](Song& song)
		{
			if (song.m_album == "[None]")
			{
				song.m_album = " ";
			}

			return song;
		};

		std::transform(this->songs.begin(), this->songs.end(), this->songs.begin(), checkNone);
	}

	bool SongCollection::inCollection(const std::string& artistName) const
	{
		return std::any_of(this->songs.begin(), this->songs.end(), [&](const Song& song) { return song.m_artist == artistName; });
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string& artistName) const
	{
		std::list<Song> artistSongs;
		
		// need to use std::back_inserter to push the element to the new container because copy_if does not push_back the copied element to the new container
		std::copy_if(this->songs.begin(), this->songs.end(), std::back_inserter(artistSongs), [&](const Song& song) { return song.m_artist == artistName; });

		return artistSongs;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{		
		out << "| " << std::setw(20) << std::left << theSong.m_title;
		out << " | " << std::setw(15) << std::left << theSong.m_artist;
		out << " | " << std::setw(20) << std::left << theSong.m_album << std::right;

		if (theSong.m_releaseYear)
		{
			out << " | " << std::setw(6) << theSong.m_releaseYear;
		}
		else
		{
			out << " | " << std::setw(6) << " ";
		}

		out << " | " << theSong.m_length / 60u << ":" << std::setw(2) << std::setfill('0') << theSong.m_length % 60u << std::setfill(' ');
		out << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |";

		return out;
	}
}
