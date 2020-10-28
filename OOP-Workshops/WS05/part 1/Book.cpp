#include <iomanip>
#include "Book.h"

namespace sdds
{	
	Book::Book() {}

	Book::Book(const std::string& strBook)
	{
		size_t startPos = 0u;
		size_t endPos = 0u;

		// lamda function that removes all leading and trailing whitespaces.
		auto removeWhiteSpaces = [](std::string str) -> std::string
		{
			str.erase(0, str.find_first_not_of(' '));
			str.erase(str.find_last_not_of(' ') + 1);

			return str;
		};

		// Book Author
		endPos = strBook.find(',');
		this->b_author = removeWhiteSpaces(strBook.substr(startPos, endPos));

		// Book Title
		startPos = endPos + 1u;
		endPos = strBook.find(',', startPos);
		this->b_title = removeWhiteSpaces(strBook.substr(startPos, endPos - startPos));

		// Book Country of Publication
		startPos = endPos + 1u;
		endPos = strBook.find(',', startPos);
		this->b_pubCountry = removeWhiteSpaces(strBook.substr(startPos, endPos - startPos));

		// Book Price
		startPos = endPos + 1u;
		endPos = strBook.find(',', startPos);
		this->b_price = std::stod(strBook.substr(startPos, endPos - startPos));

		// Book Year of Publication
		startPos = endPos + 1u;
		endPos = strBook.find(',', startPos);
		this->b_pubYear = std::stoi(strBook.substr(startPos, endPos - startPos));

		// Book Description
		startPos = endPos + 1u;
		this->b_desc = removeWhiteSpaces(strBook.substr(startPos));
	}

	const std::string& Book::title() const
	{
		return this->b_title;
	}

	const std::string& Book::country() const
	{
		return this->b_pubCountry;
	}

	const size_t& Book::year() const
	{
		return this->b_pubYear;
	}

	double& Book::price()
	{
		return this->b_price;
	}
	
	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os << std::setw(20) << book.b_author << " | ";
		os << std::setw(22) << book.b_title << " | ";
		os << std::setw(5) << book.b_pubCountry << " | ";
		os << std::setw(4) << book.b_pubYear << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << book.b_price << " | ";
		os << book.b_desc << std::endl;

		return os;
	}
}