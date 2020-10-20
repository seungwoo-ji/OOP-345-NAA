/* ------------------------------------------------------
Workshop 4: Containers
Module: Restaurant
Filename: Restaurant.h
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

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{
		Reservation* rt_reservations{ nullptr }; 
		size_t rt_count{ 0u }; 

	public:
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src); 
		Restaurant(Restaurant&& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant& operator=(Restaurant&& src);
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& rt);
	};
}

#endif // !SDDS_RESTAURANT_H
