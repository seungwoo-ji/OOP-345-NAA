/* ------------------------------------------------------
Workshop 6: STL Container
Module: Racecar 
Filename: Racecar.cpp
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
#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string str;

		getline(in, str);
		this->m_booster = std::stod(str); // throws an error when the string is empty
	}

	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << '*';
	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (this->m_booster + 1.0);
	}
}
