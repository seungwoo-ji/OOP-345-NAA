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
		friend std::ostream& operator <<(std::ostream& os, const Reservation r);
	};
}

#endif // SDDS_RESERVATION_H
