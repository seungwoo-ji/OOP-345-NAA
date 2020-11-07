/* ------------------------------------------------------
Workshop 6: STL Container
Module: Autoshop
Filename: Autoshop.h
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
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <utility>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		// added to obey the rule of five
		Autoshop() {};
		Autoshop(const Autoshop& src) = delete;
		Autoshop& operator=(const Autoshop& src) = delete;
		Autoshop(Autoshop&& src) = delete;
		Autoshop& operator=(Autoshop&& src) = delete;
		~Autoshop();
	
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto i = this->m_vehicles.begin(); i != this->m_vehicles.end(); ++i)
			{
				if (test(*i))
				{
					vehicles.push_back(*i);
				}
			}
		}
	};
}
#endif // !SDDS_AUTOSHOP_H
