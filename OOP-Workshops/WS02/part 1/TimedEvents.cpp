/* ------------------------------------------------------
Workshop 2: Move and Copy Semantics
Module: TimedEvents
Filename: TimedEvents.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/10/03	Completed workshop 2 part 1
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{
	TimedEvents::TimedEvents() {} // utilized default member initializers in the class definition

	void TimedEvents::startClock()
	{
		te_start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		te_end = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* eventName)
	{
		if (eventName != nullptr && eventName[0] != '\0' && te_numRecords < MAX_NUM_RECORDS)
		{
			te_records[te_numRecords].r_eventName = eventName;
			te_records[te_numRecords].r_timeUnit = "nanoseconds";
			te_records[te_numRecords].r_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(te_end - te_start);
			te_numRecords++;
		}
		else
		{
			std::cerr << "Error: Event cannot be recorded" << std::endl;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents te)
	{
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		
		for (int i = 0; i < te.te_numRecords; ++i)
		{
			os << std::setw(20) << std::left << te.te_records[i].r_eventName << " ";
			os << std::setw(12) << std::right << te.te_records[i].r_duration.count() << " ";
			os << te.te_records[i].r_timeUnit << std::endl;
		}

		os << "--------------------------" << std::endl;
		
		return os;
	}
}

