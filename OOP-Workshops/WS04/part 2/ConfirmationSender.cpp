/* ------------------------------------------------------
Workshop 4: Containers
Module: ConfirmationSender
Filename: ConfirmationSender.cpp
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
#include "ConfirmationSender.h"

namespace sdds
{
	ConfirmationSender::ConfirmationSender() { } // default state initialized by default member initializers in the class definition

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src)
		{
			this->c_count = src.c_count;

			delete[] this->c_ptrReservations;

			if (src.c_ptrReservations != nullptr)
			{
				this->c_ptrReservations = new const Reservation * [this->c_count];

				for (size_t i = 0u; i < this->c_count; ++i)
				{
					this->c_ptrReservations[i] = src.c_ptrReservations[i];
				}
			}
			else
			{
				this->c_ptrReservations = nullptr;
			}
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src)
		{
			this->c_count = src.c_count;

			delete[] this->c_ptrReservations;
			this->c_ptrReservations = src.c_ptrReservations;

			src.c_count = 0u;
			src.c_ptrReservations = nullptr;
		}

		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		if (this->c_ptrReservations != nullptr)
		{
			delete[] this->c_ptrReservations;
			c_ptrReservations = nullptr;
		}
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool isNotFound = true;

		for (size_t i = 0u; i < this->c_count && isNotFound; ++i) // when the address is found (isNotFound = false), isNotFound breaks the loop
		{
			isNotFound = this->c_ptrReservations[i] != &res;
		}

		if (isNotFound == true) // when the address is not found (isNotFound = true), add it to the array
		{
			const Reservation** temp = new const Reservation * [this->c_count + 1u];

			for (size_t i = 0u; i < this->c_count; ++i)
			{
				temp[i] = this->c_ptrReservations[i];
			}

			temp[this->c_count++] = &res;

			delete[] this->c_ptrReservations;
			this->c_ptrReservations = temp;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool isNotFound = true;

		for (size_t i = 0u; i < this->c_count && isNotFound; ++i) // when the address is found (isNotFound = false), isNotFound breaks the loop
		{
			isNotFound = this->c_ptrReservations[i] != &res;
		}

		if (isNotFound == false) // when the address is found (isNotFound = false), remove it from the array
		{
			const Reservation** temp = new const Reservation * [this->c_count - 1u];
			size_t tempIndex = 0u;

			for (size_t i = 0u; i < this->c_count; ++i)
			{
				if (this->c_ptrReservations[i] != &res)
				{
					temp[tempIndex] = this->c_ptrReservations[i];
					tempIndex++;
				}
			}

			this->c_count--;
			delete[] this->c_ptrReservations;
			this->c_ptrReservations = new const Reservation * [this->c_count];

			for (size_t i = 0u; i < this->c_count; ++i)
			{
				this->c_ptrReservations[i] = temp[i];
			}

			delete[] temp;
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& c)
	{
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";

		if (!c.c_count)
		{
			os << "The object is empty!\n";
		}
		else
		{
			for (size_t i = 0u; i < c.c_count; ++i)
			{
				os << *c.c_ptrReservations[i];
			}
		}

		os << "--------------------------" << std::endl;

		return os;
	}

}
