/* ------------------------------------------------------
Workshop 4: Containers
Module: ConfirmationSender
Filename: ConfirmationSender.h
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

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** c_ptrReservations{ nullptr };
		size_t c_count{ 0u };

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& c);
	};
}

#endif // !SDDS_CONFIRMATIONSENDER_H
