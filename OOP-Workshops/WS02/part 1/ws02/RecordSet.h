#ifndef _SDDS_RECORDSET_H
#define _SDDS_RECORDSET_H

#include <string>

namespace sdds
{
	class RecordSet
	{
		std::string* rs_records{ nullptr };
		size_t rs_numRecord{ 0u };

	public:
		RecordSet();
		RecordSet(const char* fileName);
		RecordSet(const RecordSet& src);
		RecordSet& operator=(const RecordSet& src);
		~RecordSet();
		size_t size() const;
		std::string getRecord(size_t index) const;
	};
}

#endif // !_SDDS_RECORDSET_H
