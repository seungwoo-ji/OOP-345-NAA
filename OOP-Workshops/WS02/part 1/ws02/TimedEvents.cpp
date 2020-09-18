#include "TimedEvents.h"

sdds::TimedEvents::TimedEvents()
{
}

void sdds::TimedEvents::startClock()
{
	te_start = std::chrono::steady_clock::now();
}

void sdds::TimedEvents::stopClock()
{
	te_end = std::chrono::steady_clock::now();
}

void sdds::TimedEvents::recordEvent(const char* eventName)
{
	if (eventName != nullptr && eventName[0] != '\0' && te_numRecords < MAX_NUM_RECORDS)
	{
		te_records[te_numRecords].ter_name = eventName;
		te_records[te_numRecords].ter_unit = "nanoseconds";
		te_records[te_numRecords].ter_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(te_end - te_start);
		te_numRecords++;
	}
	else
	{
		std::cerr << "ERROR: Event cannot be recorded" << std::endl;
	}
}

namespace sdds // question why I can't use sdds::operator<< ???
{
	std::ostream& operator<<(std::ostream& os, const TimedEvents& te)
	{
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;

		for (unsigned int i = 0; i < te.te_numRecords; ++i)
		{
			os.width(20);
			os.setf(std::ios::left);
			os << te.te_records[i].ter_name;
			os.unsetf(std::ios::left);

			os << " ";

			os.width(12);
			os << te.te_records[i].ter_duration.count();

			os << " " << te.te_records[i].ter_unit << std::endl;
		}

		os << "--------------------------" << std::endl;

		return os;
	}
}

