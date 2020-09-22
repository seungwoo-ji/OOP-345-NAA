/* ------------------------------------------------------
Workshop 1: Across Translation Units
Module: event
Filename: event.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/9/19	Completed workshop 1 part 1
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "event.h"

unsigned g_sysClock; // definition

namespace sdds
{
	Event::Event()
	{
		e_desc[0] = '\0';
		e_start = 0u;
	}

	void Event::display() const
	{
		static unsigned count{ 1u };
		unsigned hh{ 0u }, mm{ 0u }, ss{ 0u };

		std::cout.width(3);
		std::cout.fill(' ');
		std::cout << count++ << ". ";

		if (e_desc[0] != '\0')
		{
			hh = e_start / 3600;
			mm = (e_start % 3600) / 60;
			ss = (e_start % 3600) % 60;

			std::cout.width(2);
			std::cout.fill('0');
			std::cout << hh << ":";

			std::cout.width(2);
			std::cout.fill('0');
			std::cout << mm << ":";

			std::cout.width(2);
			std::cout.fill('0');
			std::cout << ss << " -> " << e_desc << std::endl;
		}
		else
		{
			std::cout << "[ No Event ]" << std::endl;
		}
	}

	void Event::setDescription(const char* desc)
	{
		if (desc != nullptr && desc[0] != '\0')
		{
			e_start = ::g_sysClock;
			strncpy(e_desc, desc, MAX_EVENT_DESC);
			e_desc[MAX_EVENT_DESC] = '\0';
		}
		else
		{
			*this = Event();
		}
	}
}