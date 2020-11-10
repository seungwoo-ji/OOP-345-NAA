/* ------------------------------------------------------
Workshop 2: Move and Copy Semantics
Module: TimedEvents
Filename: TimedEvents.h
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/10/03	Completed workshop 2 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <chrono>
#include <string>

namespace sdds
{
	const int MAX_NUM_RECORDS = 7;
	
	class TimedEvents
	{
		int te_numRecords{ 0 };
		std::chrono::steady_clock::time_point te_start{};
		std::chrono::steady_clock::time_point te_end{};
		struct 
		{
			std::string r_eventName;
			std::string r_timeUnit;
			std::chrono::steady_clock::duration r_duration;

		} te_records[MAX_NUM_RECORDS]{};

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents te);
	};
}

#endif // !SDDS_TIMEDEVENTS_H
