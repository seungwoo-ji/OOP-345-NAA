/* ------------------------------------------------------
Workshop 5: Functions and Error Handling
Module: Movie
Filename: Movie.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/10/28	Completed workshop 5 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iomanip>
#include "Movie.h"

namespace sdds
{
	Movie::Movie() {}

	Movie::Movie(const std::string& strMovie)
	{
		size_t startPos = 0u, endPos = 0u;

		// lamda function that removes all leading and trailing whitespaces.
		auto removeWhiteSpaces = [](std::string str) -> std::string
		{
			str.erase(0, str.find_first_not_of(' '));
			str.erase(str.find_last_not_of(' ') + 1);

			return str;
		};

		// Movie Title
		endPos = strMovie.find(',');
		this->mv_title = removeWhiteSpaces(strMovie.substr(startPos, endPos - startPos));

		// Movie Release Year
		startPos = endPos + 1u;
		endPos = strMovie.find(',', startPos);
		this->mv_releaseYear = std::stoi(strMovie.substr(startPos, endPos - startPos));

		// Movie Description
		startPos = endPos + 1u;
		this->mv_desc = removeWhiteSpaces(strMovie.substr(startPos));
	}

	const std::string& Movie::title() const
	{
		return this->mv_title;
	}


	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		os << std::setw(40) << movie.mv_title << " | ";
		os << std::setw(4) << movie.mv_releaseYear << " | ";
		os << movie.mv_desc << std::endl;
		
		return os;
	}

}
