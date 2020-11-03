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
		}

		out << "--------------------------------\n";
	}
}
