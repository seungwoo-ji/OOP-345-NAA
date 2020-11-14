/* ------------------------------------------------------
Workshop 7: STL Algorithms
Module: SongCollection
Filename: SongCollection.h
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
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H 

#include <iostream>
#include <string>
#include <vector>
#include <list>

// declaring the prototype of printbar function to be used for the SongCollection display member function
void printbar(std::ostream& out);

namespace sdds
{
	const size_t SIZE_OF_STR_FIELD{ 25u };
	const size_t SIZE_OF_NUM_FIELD{ 5u };

	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price{ 0.0 };
		size_t m_releaseYear{ 0u };
		size_t m_length{ 0u };
	};
	
	class SongCollection
	{
		std::vector<Song> songs;
	public:
		SongCollection(const char* filename);
		void display(std::ostream& out) const;
		void sort(const std::string& fieldName);
		void cleanAlbum();
		bool inCollection(const std::string& artistName) const;
		std::list<Song> getSongsForArtist(const std::string& artistName) const;
	};
	
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION_H
