/* ------------------------------------------------------
Workshop 3: Templates
Module: Pair
Filename: Pair.h
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

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

namespace sdds
{
	template <typename K, typename V> 
	class Pair
	{
		K p_key;
		V p_value;

	public:
		Pair() : p_key{}, p_value{} {}
		
		Pair(const K& key, const V& value) : p_key{key}, p_value{value} {}
		
		const K& key() const
		{
			return this->p_key;
		}

		const V& value() const
		{
			return this->p_value;
		}

		virtual void display(std::ostream& os) const
		{
			os << this->p_key << " : " << this->p_value << std::endl;
		}
	};

	template <typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair)
	{
		pair.display(os);
		return os;
	}
}
#endif // !SDDS_PAIR_H
