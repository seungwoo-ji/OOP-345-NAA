/* ------------------------------------------------------
Workshop 4: Containers
Module: Reservation
Filename: Reservation.cpp
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

#include <iomanip>
#include "Reservation.h"

namespace sdds
{
	Reservation::Reservation() : r_number{ 0u }, r_day{ 0u }, r_hour{ 0u } {}
	
	Reservation::Reservation(const std::string& res) : r_number{ 0u }, r_day{ 0u }, r_hour{ 0u }
	{
		size_t startPos = 0u;
		size_t endPos = 0u;

		// RESERVATION_ID
		// set the end-position to be where ':' is located
		endPos = res.find(':');
		r_reservationID = res.substr(startPos, endPos);

		// erase the leading and trailing whitespaces (' ')
		r_reservationID.erase(0, r_reservationID.find_first_not_of(' '));
		r_reservationID.erase(r_reservationID.find_last_not_of(' ') + 1);

		// RESERVATION_NAME
		// set the new start-position (previous end-position + 1) and end-position (where ',' is located)
		startPos = endPos + 1u;
		endPos = res.find(',', startPos);
		r_name = res.substr(startPos, endPos - startPos);

		// erase the leading and trailing whitespaces (' ')
		r_name.erase(0, r_name.find_first_not_of(' '));
		r_name.erase(r_name.find_last_not_of(' ') + 1);

		// RESERVATION_EMAIL
		// set the new start-position (previous end-position + 1) and end-position (where next ',' is located)
		startPos = endPos + 1u;
		endPos = res.find(',', startPos);
		r_email = res.substr(startPos, endPos - startPos);

		// erase the leading and trailing whitespaces (' ')
		r_email.erase(0, r_email.find_first_not_of(' '));
		r_email.erase(r_email.find_last_not_of(' ') + 1);

		// RESERVATION_NUMBER
		// set the new start-position (previous end-position + 1) and end-position (where next ',' is located)
		startPos = endPos + 1u;
		endPos = res.find(',', startPos);

		// stoi interprets the integer in the string while descarding any whitespaces
		r_number = std::stoi(res.substr(startPos, endPos - startPos));

		// RESERVATION_DAY
		// set the new start-position (previous end-position + 1) and end-position (where next ',' is located)
		startPos = endPos + 1u;
		endPos = res.find(',', startPos);

		// stoi interprets the integer in the string while descarding any whitespaces
		r_day = std::stoi(res.substr(startPos, endPos - startPos));

		// RESERVATION_HOUR
		// set the new start-position (previous end-position + 1)
		startPos = endPos + 1u;

		// stoi interprets the integer in the string while descarding any whitespaces
		r_hour = std::stoi(res.substr(startPos));
	}
	
	std::ostream& operator<<(std::ostream& os, const Reservation& r)
	{
		os << "Reservation " << r.r_reservationID << ": ";
		os << std::setw(10) << r.r_name << "  ";
		os << std::setw(20) << std::left << "<" + r.r_email + ">" << "    ";
		
		if (r.r_hour >= 6u && r.r_hour <= 9u)
		{
			os << "Breakfast ";
		}
		else if (r.r_hour >= 11u && r.r_hour <= 15u)
		{
			os << "Lunch ";
		}
		else if (r.r_hour >= 17u && r.r_hour <= 21u)
		{
			os << "Dinner ";
		}
		else
		{
			os << "Drinks ";
		}

		os << "on day " << r.r_day << " @ " << r.r_hour << ":00 for " << r.r_number << " people." << std::right << std::endl;

		return os;
	}
}