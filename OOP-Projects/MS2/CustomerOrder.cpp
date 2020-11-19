// Name: Seung Woo Ji
// Seneca Student ID: 116376195
// Seneca email: swji1@myseneca.ca
// Date of completion: November 14, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iomanip>
#include <utility>
#include "CustomerOrder.h"
#include "Utilities.h"

// initialize the class variables m_widthField to be 0u
size_t CustomerOrder::m_widthField = 0u;

CustomerOrder::CustomerOrder(const std::string& record)
{
	Utilities utility;
	size_t pos = 0u;
	bool more = true;	

	this->m_name = utility.extractToken(record, pos, more);
	this->m_product = utility.extractToken(record, pos, more);

	// record the copy of the current position
	size_t itemPos = pos;
	
	// count the number of items
	while (more)
	{
		utility.extractToken(record, itemPos, more);
		this->m_cntItem++;
	}

	// make a dynamic array with the size of cnt if cnt is higher than zero
	if (this->m_cntItem)
	{
		this->m_lstItem = new Item * [this->m_cntItem];
		more = true;

		for (unsigned int i = 0u; i < this->m_cntItem; ++i)
		{
			this->m_lstItem[i] = new Item(utility.extractToken(record, pos, more));
		}
	}

	if (this->m_widthField < utility.getFieldWidth())
	{
		this->m_widthField = utility.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder& src)
{
	throw std::string("Copy operation of CustomerOrder is not allowed");
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
{
	*this = std::move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
{
	if (this != &src)
	{
		this->emptyLst();
		this->m_name = std::move(src.m_name);
		this->m_product = std::move(src.m_product);
		this->m_cntItem = src.m_cntItem;
		
		this->m_lstItem = src.m_lstItem;
		src.m_lstItem = nullptr;
		src.m_cntItem = 0u;
	}

	return *this;
}

CustomerOrder::~CustomerOrder()
{
	this->emptyLst();
}

void CustomerOrder::emptyLst()
{
	if (this->m_lstItem != nullptr)
	{
		for (unsigned int i = 0u; i < this->m_cntItem; ++i)
		{
			delete this->m_lstItem[i];
		}

		delete[] this->m_lstItem;
		this->m_lstItem = nullptr;
	}
}

bool CustomerOrder::isOrderFilled() const
{
	bool result = true;

	for (unsigned int i = 0u; i < this->m_cntItem && result; ++i)
	{
		result = this->m_lstItem[i]->m_isFilled;
	}
	
	return result;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
	bool result = true, isFound = false;
	
	for (unsigned int i = 0u; i < this->m_cntItem && !isFound; ++i)
	{
		if (this->m_lstItem[i]->m_itemName == itemName)
		{
			result = this->m_lstItem[i]->m_isFilled;
			isFound = true;
		}
	}

	return result;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	bool isFound = false;

	for (unsigned int i = 0u; i < this->m_cntItem && !isFound; ++i)
	{
		if (this->m_lstItem[i]->m_itemName == station.getItemName())
		{
			isFound = true;

			if (station.getQuantity() > 0u)
			{
				station.updateQuantity();
				this->m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				this->m_lstItem[i]->m_isFilled = true;

				os << std::setw(11) << "Filled " << this->m_name << ", " << this->m_product << " [" << this->m_lstItem[i]->m_itemName << ']' << std::endl;
			}
			else
			{
				os << "Unable to fill " << this->m_name << ", " << this->m_product << " [" << this->m_lstItem[i]->m_itemName << ']' << std::endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const
{
	os << this->m_name << " - " << this->m_product << std::endl;

	for (unsigned int i = 0u; i < this->m_cntItem; ++i)
	{
		os << '[' << std::setw(6) << std::setfill('0') << this->m_lstItem[i]->m_serialNumber << std::setfill(' ');
		os << "] " << std::setw(this->m_widthField) << std::left << this->m_lstItem[i]->m_itemName << std::right;
		os << " - " << (this->m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << std::endl;
	}
}

