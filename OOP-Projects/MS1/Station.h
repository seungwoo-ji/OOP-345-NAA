// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 14, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef STATION_H
#define STATION_H

#include <string>

class Station
{
	size_t stationID{ 0u };
	std::string stationItem;
	std::string stationDesc;
	size_t nextSerialNumber{ 0u };
	size_t quantity{ 0u };
	static size_t m_widthField;
	static size_t id_generator;

public:
	Station(const std::string& record);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};
#endif // !STATION_H
