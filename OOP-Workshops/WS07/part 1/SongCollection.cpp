#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
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

			song.title = removeWhiteSpaces(line.substr(startPos, SIZE_OF_STR_FIELD));

			startPos += SIZE_OF_STR_FIELD;
			song.artist = removeWhiteSpaces(line.substr(startPos, SIZE_OF_STR_FIELD));

			startPos += SIZE_OF_STR_FIELD;
			song.album = removeWhiteSpaces(line.substr(startPos, SIZE_OF_STR_FIELD));

			startPos += SIZE_OF_STR_FIELD;

			// set the release year of the song to be 0 if the conversion cannot be performed
			try
			{
				song.releaseYear = std::stoi((line.substr(startPos, SIZE_OF_NUM_FIELD)));
			}
			catch (std::invalid_argument&)
			{
				song.releaseYear = 0u;
			}

			startPos += SIZE_OF_NUM_FIELD;

			// set the length of the song to be 0 if the conversion cannot be performed
			try
			{
				song.length = std::stoi((line.substr(startPos, SIZE_OF_NUM_FIELD)));
			}
			catch (std::invalid_argument&)
			{
				song.length = 0u;
			}

			startPos += SIZE_OF_NUM_FIELD;

			// set the price of the song to be 0 if the conversion cannot be performed
			try
			{
				song.price = std::stod((line.substr(startPos, SIZE_OF_NUM_FIELD)));
			}
			catch (std::invalid_argument&)
			{
				song.price = 0.0;
			}
					
			this->songs.push_back(song);
		}

		file.close();
	}

	void SongCollection::display(std::ostream& out) const
	{
		std::for_each(songs.begin(), songs.end(), [&](const Song& song) {out << song << std::endl; });
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{		
		out << "| " << std::setw(20) << std::left << theSong.title;
		out << " | " << std::setw(15) << std::left << theSong.artist;
		out << " | " << std::setw(20) << std::left << theSong.album;

		if (theSong.releaseYear)
		{
			out << " | " << std::setw(6) << std::right << theSong.releaseYear;
		}
		else
		{
			out << " | " << std::setw(6) << " ";
		}

		out << " | " << theSong.length / 60 << ":" << std::setw(2) << std::setfill('0') << theSong.length % 60 << std::setfill(' ');
		out << " | " << std::fixed << std::setprecision(2) << theSong.price << " |";

		return out;
	}
}
