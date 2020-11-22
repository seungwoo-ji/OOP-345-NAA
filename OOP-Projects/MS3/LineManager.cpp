// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 19, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <fstream>
#include <algorithm>
#include <utility>
#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(const std::string& filename, std::vector<Workstation*>& workstations, std::vector<CustomerOrder>& toBeFilled)
{
	std::ifstream file(filename);

	if (!file)
	{
		throw std::string("Unable to open [") + filename + "] file.";
	}

	Utilities utility;
	size_t pos = 0u;
	bool more = true;
	std::string record, itemName;
	Workstation* stationOne = nullptr;
	Workstation* stationTwo = nullptr;
	std::vector<Workstation*>::iterator itr;

	// predicate lambda expression to find a Workstation pointer that has a matching name with the items from AssemblyLine.txt
	auto isFound = [&](const Workstation* ws)
	{
		return ws->getItemName() == itemName;
	};

	// link each Workstation object to form the assembly line
	while (std::getline(file, record))
	{
		itemName = utility.extractToken(record, pos, more);
		itr = std::find_if(workstations.begin(), workstations.end(), isFound);
		stationOne = itr != workstations.end() ? *itr : throw std::string("No station manages [") + itemName + "] item.";

		if (more)
		{
			itemName = utility.extractToken(record, pos, more);
			itr = std::find_if(workstations.begin(), workstations.end(), isFound);
			stationTwo = itr != workstations.end() ? *itr : throw std::string("No station manages [") + itemName + "] item.";
		}
	
		if (stationTwo)
		{
			stationOne->setNextStation(*stationTwo);
		}
		
		stationOne = nullptr;
		stationTwo = nullptr;
		pos = 0u;
		more = true;

	}

	file.close();

	// move all the CustomerOrder objects onto the back of the ToBeFilled queue
	this->m_cntCustomerOrder = toBeFilled.size();

	for (auto& order : toBeFilled)
	{
		this->ToBeFilled.push_back(std::move(order));
	}
	
	// copy all the Workstation objects into the AssemblyLine container
	std::copy(workstations.begin(), workstations.end(), std::back_inserter(this->AssemblyLine));
}


bool LineManager::run(std::ostream& os)
{
	// local static counter to count how many times this function has been called by the client
	static unsigned int runCount = 1u;
	os << "Line Manager Iteration: " << runCount++ << std::endl;


	if (!this->ToBeFilled.empty())
	{
		*(this->findFirstStation()) += std::move(this->ToBeFilled.front());
		this->ToBeFilled.pop_front();
	}

	CustomerOrder order;

	auto moveLine = [&](Workstation* stn)
	{
		bool isMoved = stn->moveOrder();
			
		if (!isMoved)
		{
			if (stn->getIfCompleted(order))
			{
				Completed.push_back(std::move(order));
			}
		}
	};

	std::for_each(this->AssemblyLine.begin(), this->AssemblyLine.end(), [&](Workstation* stn) { stn->runProcess(os); });
	std::for_each(this->AssemblyLine.begin(), this->AssemblyLine.end(), moveLine);

	return this->Completed.size() == this->m_cntCustomerOrder;
}

void LineManager::displayCompletedOrders(std::ostream& os) const
{
	std::for_each(this->Completed.begin(), this->Completed.end(), [&](const CustomerOrder& order) { order.display(os); });
}

void LineManager::displayStations() const
{
	std::for_each(this->AssemblyLine.begin(), this->AssemblyLine.end(), [](const Workstation* stn) { stn->display(std::cout); });
}

void LineManager::displayStationsSorted() const
{
	const Workstation* station = this->findFirstStation();

	while (station)
	{
		station->display(std::cout);
		station = station->getNextStation();
	}
}

// identify the starting station of the assembly line
Workstation* LineManager::findFirstStation() const
{
	Workstation* first = nullptr;
	bool flag = true;

	for (auto i = this->AssemblyLine.begin(); i != this->AssemblyLine.end() && flag; ++i)
	{
		bool isFound = false;

		for (auto j = this->AssemblyLine.begin(); j != this->AssemblyLine.end(); ++j)
		{
			if ((*j)->getNextStation())
			{ 
				if ((*i)->getItemName() == (*j)->getNextStation()->getItemName())
				{
					isFound = true;
				}
			}
		}

		if (!isFound)
		{
			first = *i;
			flag = false;
		}
	}

	return first;
}

