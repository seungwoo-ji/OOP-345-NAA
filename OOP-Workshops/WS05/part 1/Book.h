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
	};
}
#endif // !SDDS_BOOK_H
