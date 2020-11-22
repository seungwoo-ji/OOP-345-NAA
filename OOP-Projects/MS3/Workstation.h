// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 19, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

class Workstation :public Station
{
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation{ nullptr };

public:
	Workstation(const std::string& record);
	Workstation(const Workstation& src) = delete;
	Workstation& operator=(const Workstation& src) = delete;
	Workstation(Workstation&& src) = delete;
	Workstation& operator=(Workstation&& src) = delete;
	void runProcess(std::ostream& os);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream& os) const;
	Workstation& operator+=(CustomerOrder&& order);
};
#endif // !WORKSTATION_H
