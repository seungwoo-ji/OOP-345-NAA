/* ------------------------------------------------------
Workshop 4: Containers
Module: Reservation
Filename: Reservation.h
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

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds
{
	class Reservation
	{
		std::string r_reservationID;
		std::string r_name;
		std::string r_email;
		unsigned r_number;
		unsigned r_day;
		unsigned r_hour;

	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator <<(std::ostream& os, const Reservation& r);
	};
}

#endif // SDDS_RESERVATION_H
