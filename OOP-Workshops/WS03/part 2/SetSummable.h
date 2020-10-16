/* ------------------------------------------------------
Workshop 3: Templates
Module: SetSummable
Filename: SetSummable.h
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

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include <string>
#include "Set.h"

namespace sdds
{
	template <typename T, unsigned N>
	class SetSummable : public Set<T, N>
	{
	public:
		T accumulate(const std::string& filter) const
		{
			T filteredElements(filter);

			for (size_t i = 0u; i < this->size(); ++i)
			{
				filteredElements += (*this)[i];
			}

			return filteredElements;
		}
	};
}

#endif // !SDDS_SETSUMMABLE_H
