// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 19, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <vector>
#include "Workstation.h"

class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder{ 0u };

public:
	LineManager(const std::string& filename, std::vector<Workstation*>& workstations, std::vector<CustomerOrder>& toBeFilled);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
	Workstation* findFirstStation() const; // identify the starting station of the assembly line
};
#endif // !LINEMANAGER_H
