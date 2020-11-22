// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 19, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef STATION_H
#define STATION_H

#include <string>

class Station
{
	unsigned int stationID{ 0u };
	std::string stationItem;
	std::string stationDesc;
	unsigned int nextSerialNumber{ 0u };
	unsigned int quantity{ 0u };
	static size_t m_widthField;
	static unsigned int id_generator;

public:
	Station(const std::string& record);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
	virtual ~Station() {}; // included the destructor with the keyword "virtual" in order to make workstation and station objects to be polymorphic
};
#endif // !STATION_H
