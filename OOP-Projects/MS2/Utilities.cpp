// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 14, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include "Utilities.h"

// initialize the class variable m_delimiter to be a whitespace
char Utilities::m_delimiter = ' ';

void Utilities::setFieldWidth(size_t newWidth)
{
	this->m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const
{
	return this->m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string token;

	if (more)
	{
		size_t delimitPos = str.find(this->m_delimiter, next_pos);

		more = delimitPos == std::string::npos ? false : true;

		token = str.substr(next_pos, delimitPos - next_pos);

		// remove leading and trailing whitespaces if possible
		token.erase(0, token.find_first_not_of(' '));
		token.erase(token.find_last_not_of(' ') + 1);

		next_pos = delimitPos + 1;

		if (token.empty())
		{
			throw std::string("No token found");
		}
		else if (token.size() > this->m_widthField)
		{
			this->m_widthField = token.size();
		}
	}

	return token;
}

void Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter()
{
	return m_delimiter;
}


