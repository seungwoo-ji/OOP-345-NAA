/* ------------------------------------------------------
Workshop 5: Functions and Error Handling
Module: Book
Filename: Book.h
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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <ostream>
#include <string>

namespace sdds
{
	class Book
	{
		std::string b_author;
		std::string b_title;
		std::string b_pubCountry;
		double b_price{ 0.0 };
		size_t b_pubYear{ 0u };
		std::string b_desc;

	public:
		Book();
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator<<(std::ostream& os, const Book& book);

		template <typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(this->b_desc);
		}
	};
}
#endif // !SDDS_BOOK_H
