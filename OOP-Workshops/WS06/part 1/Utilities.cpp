#include <string>
#include <sstream>
#include "Utilities.h"
#include "Car.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ptrV = nullptr;
		std::string record;
		
		std::getline(in, record);
		std::stringstream sstr(record);

		if (record[0] == 'c' || record[0] == 'C')
		{
			ptrV = new Car(sstr);
		}

		return ptrV;
	}
}
