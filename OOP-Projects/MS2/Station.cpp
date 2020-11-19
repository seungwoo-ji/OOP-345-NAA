// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 14, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

// initialize the class variables m_widthField and id_generator to be 0u
size_t Station::m_widthField = 0u;
unsigned int Station::id_generator = 0u;

Station::Station(const std::string& record)
{
	Utilities utility;
	size_t pos = 0u;
	bool more = true;

	this->stationItem = utility.extractToken(record, pos, more);
	this->nextSerialNumber = std::stoi(utility.extractToken(record, pos, more));
	this->quantity = std::stoi(utility.extractToken(record, pos, more));

	if (this->m_widthField < utility.getFieldWidth())
	{
		this->m_widthField = utility.getFieldWidth();
	}

	this->stationDesc = utility.extractToken(record, pos, more);
	this->stationID = ++id_generator;
}

const std::string& Station::getItemName() const
{
	return this->stationItem;
}

unsigned int Station::getNextSerialNumber()
{
	return this->nextSerialNumber++;
}

unsigned int Station::getQuantity() const
{
	return this->quantity;
}

void Station::updateQuantity()
{
	if (this->quantity > 0)
	{
		this->quantity--;
	}
	else
	{
		std::cerr << "Item quantity cannot go below zero" << std::endl;
	}
}

void Station::display(std::ostream& os, bool full) const
{
	if (full)
	{
		os << '[' << std::setw(3) << std::setfill('0') << this->stationID << std::setfill(' ');
		os << "] Item: " << std::setw(this->m_widthField) << std::left << this->stationItem << std::right;
		os << " [" << std::setw(6) << std::setfill('0') << this->nextSerialNumber << std::setfill(' ');
		os << "] Quantity: " << std::setw(this->m_widthField) << std::left << this->quantity << std::right;
		os << " Description: " << this->stationDesc << std::endl;
	}
	else
	{
		os << '[' << std::setw(3) << std::setfill('0') << this->stationID << std::setfill(' ');
		os << "] Item: " << std::setw(this->m_widthField) << std::left << this->stationItem << std::right;
		os << " [" << std::setw(6) << std::setfill('0') << this->nextSerialNumber << std::setfill(' ') << ']' << std::endl;
	}
}

