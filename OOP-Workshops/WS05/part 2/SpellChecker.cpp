/* ------------------------------------------------------
Workshop 5: Functions and Error Handling
Module: SpellChecker
Filename: SpellChecker.cpp
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

#include <fstream>
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);

		if (!file)
		{
			throw "Bad file name!"; // throws an exception of type const char*
		}

		std::string line;
		size_t cnt = 0u;
		
		while (std::getline(file, line))
		{
			size_t startPos = 0u, endPos = 0u;

			endPos = line.find(" ");
			this->m_badWords[cnt] = line.substr(0, endPos);

			startPos = endPos + 1;
			this->m_goodWords[cnt] = line.substr(startPos, endPos - startPos);
			this->m_goodWords[cnt].erase(0, this->m_goodWords[cnt].find_first_not_of(' '));

			cnt++;
		}
		file.close();
	}
	
	void SpellChecker::operator()(std::string& text) const
	{
		for (size_t i = 0u; i < numOfWords; ++i)
		{
			while (text.find(this->m_badWords[i]) != std::string::npos)
			{
				text.replace(text.find(this->m_badWords[i]), this->m_badWords[i].length(), this->m_goodWords[i]);
			}
		}
	}
}