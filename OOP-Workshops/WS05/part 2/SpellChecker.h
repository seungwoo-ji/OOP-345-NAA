/* ------------------------------------------------------
Workshop 5: Functions and Error Handling
Module: SpellChecker
Filename: SpellChecker.h
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

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

namespace sdds
{
	const unsigned numOfWords = 5;

	class SpellChecker
	{
		std::string m_badWords[numOfWords];
		std::string m_goodWords[numOfWords];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}

#endif // !SDDS_SPELLCHECKER_H
