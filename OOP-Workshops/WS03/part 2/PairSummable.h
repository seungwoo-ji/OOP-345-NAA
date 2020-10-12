/* ------------------------------------------------------
Workshop 3: Templates
Module: PairSummable
Filename: PairSummable.h
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/10/10	Completed workshop 3 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include <string>
#include <iomanip>
#include "Pair.h"

namespace sdds
{
	template<typename K, typename V>
	class PairSummable : public Pair<K, V>
	{
		static V ps_init;
		static size_t ps_width;

	public:
		PairSummable() {}

		PairSummable(const K& key, const V& value = ps_init) : Pair<K, V>(key, value)
		{
			// assume that the type K supports a function named size() (i.e. string::size)
			
			if (ps_width < key.size())
			{
				ps_width = key.size();
			}
		}

		PairSummable& operator+=(const PairSummable& item)
		{
			// check if both objects share the same key but not the address
			if (this != &item && this->key() == item.key())
			{
				PairSummable temp(this->key(), this->value() + item.value());
				*this = temp;
			}

			return *this;
		}

		void display(std::ostream& os) const
		{
			os << std::left << std::setw(ps_width);
			Pair<K, V>::display(os);
			os << std::right;
		}
	};

	//initialize the minimum field width with 0
	template<typename K, typename V>
	size_t PairSummable<K, V>::ps_width = 0u;

	// specializations
	template<>
	std::string PairSummable<std::string, std::string>::ps_init = "";

	template<>
	int PairSummable<std::string, int>::ps_init = 0;

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& item)
	{
		// check if both objects share the same key but not the address as well as if the item key and value are not empty string
		if (this != &item && this->key() == item.key() && this->key() != "" && item.value() != "")
		{
			// check if the object is empty 
			if (this->value() == "")
			{
				PairSummable<std::string, std::string> temp(this->key(), this->value() + item.value());
				*this = temp;
			}
			else
			{
				PairSummable<std::string, std::string> temp(this->key(), this->value() + ", " + item.value());
				*this = temp;
			}
		}

		return *this;
	}
}
#endif // !SDDS_PAIRSUMMABLE_H
