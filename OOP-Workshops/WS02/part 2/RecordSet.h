/* ------------------------------------------------------
Workshop 2: Move and Copy Semantics
Module: RecordSet
Filename: RecordSet.h
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

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <string>

namespace sdds
{
	class RecordSet
	{
		std::string* rs_records;
		size_t rs_numRecords;

	public:
		RecordSet();
		RecordSet(const char* fileName);
		RecordSet(const RecordSet& src);
		RecordSet(RecordSet&& src); // move constructor
		RecordSet& operator=(const RecordSet& src);
		RecordSet& operator=(RecordSet&& src); // move assignment operator
		~RecordSet();
		size_t size() const;
		std::string getRecord(size_t index) const;
	};
}

#endif // !SDDS_RECORDSET_H
