#ifndef _SDDS_TIMEDEVENTS_H
#define _SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds
{
	const unsigned int MAX_NUM_RECORDS = 7; // maximum number of record objects

	class TimedEvents
	{
		size_t te_numRecords{ 0u };
		std::chrono::steady_clock::time_point te_start; // how do I initialize this type?
		std::chrono::steady_clock::time_point te_end;
		struct
		{
			std::string ter_name; // question: because the manual said string, can I use the string here? 
			std::string ter_unit;
			std::chrono::steady_clock::duration ter_duration{ std::chrono::steady_clock::duration::zero() };
		} te_records[MAX_NUM_RECORDS];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& te);
	};
}
#endif // !_SDDS_TIMEDEVENTS_H
