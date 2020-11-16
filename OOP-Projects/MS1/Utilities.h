#ifndef UTILITIES_H
#define UTILITIES_H

// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 14, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <string>

class Utilities
{
	size_t m_widthField{ 1u };
	static char m_delimiter;

public:
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};
#endif // !UTILITIES_H
