/* ------------------------------------------------------
Workshop 6: STL Container
Module: Autoshop
Filename: Autoshop.cpp
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
#include "Autoshop.h"

namespace sdds
{
	Autoshop::~Autoshop()
	{
		if (!this->m_vehicles.empty())
		{
			auto i = this->m_vehicles.begin();

			while (i != this->m_vehicles.end())
			{
				delete* i;
				*i = nullptr;
				i =	this->m_vehicles.erase(i);
			}
		}
	}

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		this->m_vehicles.push_back(theVehicle);

		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";

		for (auto i = this->m_vehicles.begin(); i != this->m_vehicles.end(); ++i)
		{
			(*i)->display(out);
			out << std::endl;
		}

		out << "--------------------------------\n";
	}
}
