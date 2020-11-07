/* ------------------------------------------------------
Workshop 6: STL Container
Module: Utilities 
Filename: Utilities.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/03	Completed workshop 6 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <string>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* ptrV = nullptr;
		std::string record;
		char type = '\0';

		std::getline(in, record);
		std::stringstream sstr(record);
		sstr >> type;
		sstr.seekg(0);
		
		if (!record.empty())
		{
			if (type == 'c' || type == 'C')
			{
				ptrV = new Car(sstr);
			}
			else if (type == 'r' || type == 'R')
			{
				ptrV = new Racecar(sstr);
			}
			else
			{
				throw std::string("Unrecognized record type: [") + type + "]";
			}
		}

		return ptrV;
	}
}
