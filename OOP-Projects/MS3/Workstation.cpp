// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 19, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <utility>
#include "Workstation.h"

Workstation::Workstation(const std::string& record) : Station(record) {}

void Workstation::runProcess(std::ostream& os)
{
	if (!(this->m_orders.empty()))
	{
		this->m_orders.front().fillItem(*this, os);
	}
}

bool Workstation::moveOrder()
{
	bool result = false;

	if (!this->m_orders.empty() && this->m_orders.front().isItemFilled(this->getItemName()) && this->m_pNextStation)
	{
		*this->m_pNextStation += std::move(this->m_orders.front());
		this->m_orders.pop_front();

		result = true;
	}

	return result;
}

void Workstation::setNextStation(Station& station)
{
	this->m_pNextStation = dynamic_cast<Workstation*>(&station);
}

const Workstation* Workstation::getNextStation() const
{
	return this->m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order)
{
	bool result = false;
	
	if (!this->m_orders.empty() && this->m_orders.front().isOrderFilled())
	{
		order = std::move(this->m_orders.front());
		this->m_orders.pop_front();
		result = true;
	}

	return result;
}

void Workstation::display(std::ostream& os) const
{
	if (this->m_pNextStation)
	{
		os << this->getItemName() << " --> " << this->m_pNextStation->getItemName() << std::endl;
	}
	else
	{
		os << this->getItemName() << " --> END OF LINE" << std::endl;
	}
}

Workstation& Workstation::operator+=(CustomerOrder&& order)
{
	this->m_orders.push_back(std::move(order));

	return *this;
}


