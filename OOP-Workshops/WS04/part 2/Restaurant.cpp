/* ------------------------------------------------------
Workshop 4: Containers
Module: Restaurant
Filename: Restaurant.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/10/18	Completed workshop 4 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <utility>
#include "Restaurant.h"

namespace sdds
{
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		// check if the array of pointers is nullptr and cnt is higher than 0
		if (reservations != nullptr && cnt > 0u)
		{
			this->rt_reservations = new Reservation[cnt];

			for (size_t i = 0u; i < cnt; ++i)
			{
				this->rt_reservations[i] = *reservations[i];
				this->rt_count++;
			}
		}

		// if not, the class data members will be values that are set by default member initializers within the class definition 
	}

	Restaurant::Restaurant(const Restaurant& src)
	{
		*this = src;
	}

	Restaurant::Restaurant(Restaurant&& src)
	{
		*this = std::move(src);
	}

	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src)
		{
			this->rt_count = src.rt_count;

			delete[] this->rt_reservations;

			if (src.rt_reservations != nullptr)
			{
				this->rt_reservations = new Reservation[this->rt_count];

				for (size_t i = 0u; i < this->rt_count; ++i)
				{
					this->rt_reservations[i] = src.rt_reservations[i];
				}
			}
			else
			{
				this->rt_reservations = nullptr;
			}
		}

		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src)
	{
		if (this != &src)
		{
			this->rt_count = src.rt_count;

			delete[] this->rt_reservations;
			this->rt_reservations = src.rt_reservations;

			src.rt_reservations = nullptr;
			src.rt_count = 0u;
		}

		return *this;
	}

	Restaurant::~Restaurant()
	{
		if (this->rt_reservations != nullptr)
		{
			delete[] this->rt_reservations;
			this->rt_reservations = nullptr;
		}
	}

	size_t Restaurant::size() const
	{
		return this->rt_count;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& rt)
	{
		os << "--------------------------\n";
		os << "Fancy Restaurant\n";
		os << "--------------------------\n";

		if (!rt.size())
		{
			os << "The object is empty!\n";
		}
		else
		{
			for (size_t i = 0u; i < rt.rt_count; ++i)
			{
				os << rt.rt_reservations[i];
			}
		}

		os << "--------------------------" << std::endl;

		return os;
	}
}

