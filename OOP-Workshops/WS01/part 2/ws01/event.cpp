/* ------------------------------------------------------
Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
Module: event
Filename: event.cpp
Version 1.0
Author Seung Woo Ji
Student Number 116376195
Email swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/8/7	Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "event.h"

unsigned int g_sysClock;

sdds::Event::Event() {}

sdds::Event::Event(const Event& src)
{
	*this = src;
}

void sdds::Event::display() const
{
	static unsigned int count{ 1u };
	int hh{ 0u }, mm{ 0u }, ss{ 0u };

	std::cout.width(3);
	std::cout.fill(' ');
	std::cout << count++ << ". ";

	if (e_desc != nullptr)
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

void sdds::Event::setDescription(const char* desc)
{
	if (desc != nullptr && desc[0] != '\0')
	{
		delete[] e_desc;
		e_start = ::g_sysClock;
		e_desc = new char[strlen(desc) + 1];
		strcpy(e_desc, desc);
	}
	else
	{
		delete[] e_desc;
		e_desc = nullptr;
		*this = Event();
	}
}

sdds::Event& sdds::Event::operator=(const Event& src)
{
	if (this != &src)
	{
		// shallow copy non-resource variable
		e_start = src.e_start;
		// deallocate previously allocated dynamic memory
		delete[] e_desc;
		// allocate new dynamic memory if needed
		if (src.e_desc != nullptr)
		{
			e_desc = new char[strlen(src.e_desc) + 1];
			strcpy(e_desc, src.e_desc);
		}
		else
		{
			e_desc = nullptr;
		}
	}

	return *this;
}

sdds::Event::~Event()
{
	delete[] e_desc;
	e_desc = nullptr;
}