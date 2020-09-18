#include <iostream>
#include <fstream>
#include "RecordSet.h"

sdds::RecordSet::RecordSet()
{
}

sdds::RecordSet::RecordSet(const char* fileName)
{
	size_t count = 0u;
	std::string record;
	
	std::ifstream in(fileName);

	if (!in) // checks if the file is opened successfully
	{
		std::cerr << "File failed to open" << std::endl;
	}
	else
	{
		while (std::getline(in, record, ' '))
		{
			count++;
		}

		rs_records = new std::string[count];

		in.clear(); // clears eofbit
		//in.open(fileName); // reopens the file***
		in.seekg(0); // sets the current position to the beginning
		
		for (size_t i = 0; i < count; ++i)
		{
			std::getline(in, rs_records[i], ' ');
		}

		in.close();
	}
}

sdds::RecordSet::RecordSet(const RecordSet& src)
{
	*this = src;
}

sdds::RecordSet& sdds::RecordSet::operator=(const sdds::RecordSet& src)
{
	if (this != &src)
	{
		rs_numRecord = src.rs_numRecord;
		
		delete[] rs_records;
		
		if (src.rs_records != nullptr)
		{
			rs_records = new std::string[src.rs_numRecord];

			for (size_t i = 0; i < src.rs_numRecord; ++i)
			{
				rs_records[i] = src.rs_records[i];
			}
		}
		else
		{
			rs_records = nullptr;
		}
	}

	return *this;
}

sdds::RecordSet::~RecordSet()
{
	delete[] rs_records;
	rs_records = nullptr;
}

size_t sdds::RecordSet::size() const
{
	return rs_numRecord;
}

std::string sdds::RecordSet::getRecord(size_t index) const
{
	std::string record = "";

	if (rs_records != nullptr) //  && index <= rs_numRecord
	{
		record = rs_records[index];
	}
	
	return record;
}