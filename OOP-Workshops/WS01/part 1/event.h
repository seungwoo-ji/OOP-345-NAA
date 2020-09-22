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
2020/9/19	Completed workshop 1 part 1
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef EVENT_H
#define EVENT_H

extern unsigned g_sysClock; // declaration

namespace sdds
{
	const unsigned MAX_EVENT_DESC = 127;

	class Event 
	{
		char e_desc[MAX_EVENT_DESC + 1]; // C-style null-terminated string of up to 128 characters including the null terminator
		unsigned e_start;

	public:
		Event();
		void display() const;
		void setDescription(const char* desc);
	};
}

#endif // !EVENT_H
