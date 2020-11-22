// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 19, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <string>
#include <iostream>
#include "Station.h"

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0u;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem{ 0u };
	Item** m_lstItem{ nullptr };
	static size_t m_widthField;

public:
	CustomerOrder() {};
	CustomerOrder(const std::string& record);
	CustomerOrder(const CustomerOrder& src);
	CustomerOrder& operator=(const CustomerOrder& src) = delete;
	CustomerOrder(CustomerOrder&& src) noexcept;
	CustomerOrder& operator=(CustomerOrder&& src) noexcept;
	~CustomerOrder();
	
	void emptyLst(); // deallocate the array of pointers and its pointer elements
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};	
#endif // !CUSTOMERORDER_H
