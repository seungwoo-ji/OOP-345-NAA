/* ------------------------------------------------------
Workshop 2: Move and Copy Semantics
Module: RecordSet
Filename: RecordSet.cpp
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

#include <iostream>
#include <fstream>
#include "RecordSet.h"

namespace sdds
{
	RecordSet::RecordSet() : rs_records{ nullptr }, rs_numRecords{ 0u } {} // used member list initializers unlike the TimedEvent class

	RecordSet::RecordSet(const char* fileName) : rs_records{ nullptr }, rs_numRecords{ 0u }
	{
		std::string record;

		if (fileName != nullptr && fileName[0] != '\0')
		{
			std::ifstream in(fileName);

			if (in) // checks if the file is opened successfully
			{
				while (std::getline(in, record, ' '))
				{
					rs_numRecords++;
				}

				in.clear();  // clear failed (eof) state
				in.seekg(0); // rewind the input stream

				rs_records = new std::string[rs_numRecords];

				for (size_t i = 0u; i < rs_numRecords; ++i)
				{
					std::getline(in, record, ' ');
					rs_records[i] = record;
				}

				in.close();
			}
			else
			{
				std::cerr << "Error: File is not open" << std::endl;
			}
		}
		else
		{
			std::cerr << "Error: Invalid file name" << std::endl;
		}
	}

	RecordSet::RecordSet(const RecordSet& src) : rs_records{ nullptr }
	{
		*this = src;
	}

	RecordSet::RecordSet(RecordSet&& src) : rs_records{ nullptr }
	{
		*this = std::move(src);
	}

	RecordSet& RecordSet::operator=(const RecordSet& src)
	{
		if (this != &src)
		{
			this->rs_numRecords = src.rs_numRecords; // shallow copy

			delete[] this->rs_records;

			if (src.rs_records != nullptr)
			{
				this->rs_records = new std::string[this->rs_numRecords];

				for (size_t i = 0u; i < this->rs_numRecords; ++i)
				{
					this->rs_records[i] = src.rs_records[i];
				}
			}
			else
			{
				this->rs_records = nullptr;
			}
		}

		return *this;
	}

	RecordSet& RecordSet::operator=(RecordSet&& src)
	{
		if (this != &src)
		{
			// shallow copy
			this->rs_numRecords = src.rs_numRecords;

			// deallocate the memory
			delete[] this->rs_records;

			// move the resource
			this->rs_records = src.rs_records;

			src.rs_numRecords = 0u;
			src.rs_records = nullptr;
		}

		return *this;
	}

	RecordSet::~RecordSet()
	{
		if (this->rs_records != nullptr)
		{
			delete[] this->rs_records;
			this->rs_records = nullptr;
		}
	}

	size_t RecordSet::size() const
	{
		return this->rs_numRecords;
	}

	std::string RecordSet::getRecord(size_t index) const
	{
		std::string record;

		if (index < rs_numRecords)
		{
			record = rs_records[index];
		}

		return record;
	}
}
