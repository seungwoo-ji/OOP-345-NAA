/* ------------------------------------------------------
Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
Module: event
Filename: event.h
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

#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H

extern unsigned int g_sysClock; // needs to be declared with external linkage because event.h file is included in multiple cpp files and thus resulting in multiple definitions

namespace sdds
{
	class Event
	{
		char* e_desc{ nullptr }; // stores a c-style null-terminated string of any length
		unsigned int e_start{ 0u };

	public:
		Event(); // default constructor
		Event(const Event& src); // copy constructor
		void display() const;
		void setDescription(const char* desc);
		Event& operator=(const Event& src); // copy assignment operator
		~Event();
	};
}
#endif // !_SDDS_EVENT_H
