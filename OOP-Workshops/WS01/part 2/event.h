/* ------------------------------------------------------
Workshop 1: Across Translation Units
Module: event
Filename: event.h
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/9/22	Completed workshop 1 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef EVENT_H
#define EVENT_H

extern unsigned g_sysClock; // declaration

namespace sdds
{
	class Event 
	{
		char* e_desc;
		unsigned e_start;

	public:
		Event();
		~Event();
		Event(const Event& src); // copy constructor
		Event& operator=(const Event& src); // copy assignment operator
		void display() const;
		void setDescription(const char* desc);
	};
}

#endif // !EVENT_H
