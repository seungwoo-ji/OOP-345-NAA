#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H 

#include <iostream>
#include <string>
#include <vector>

namespace sdds
{
	const size_t SIZE_OF_STR_FIELD{ 25u };
	const size_t SIZE_OF_NUM_FIELD{ 5u };

	struct Song
	{
		std::string artist;
		std::string title;
		std::string album;
		double price{ 0.0 };
		size_t releaseYear{ 0u };
		size_t length{ 0u };
	};
	
	class SongCollection
	{
		std::vector<Song> songs;
	public:
		SongCollection(const char* filename);
		void display(std::ostream& out) const;

	};
	
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION_H
