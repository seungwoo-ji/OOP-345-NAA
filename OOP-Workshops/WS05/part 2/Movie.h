/* ------------------------------------------------------
Workshop 5: Functions and Error Handling
Module: Movie
Filename: Movie.h
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

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds
{
	class Movie
	{
		std::string mv_title;
		size_t mv_releaseYear{ 0u };
		std::string mv_desc;

	public:
		Movie();
		Movie(const std::string& strMovie);
		const std::string& title() const;
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

		template <typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(this->mv_title);
			spellChecker(this->mv_desc);
		}
	};
}
#endif // !SDDS_MOVIE_H
