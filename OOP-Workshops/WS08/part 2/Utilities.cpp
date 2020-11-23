/* ------------------------------------------------------
Workshop 8: Smart Pointers
Module: Utilities
Filename: Utilities.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/20	Completed workshop 8 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		bool isFound = false;

		for (size_t i = 0u; i < desc.size(); ++i)
		{
			for (size_t j = 0u; j < price.size() && !isFound; ++j)
			{
				if (desc[i].code == price[j].code)
				{
					isFound = true;

					Product* product = new Product(desc[i].desc, price[j].price);
					product->validate();
					priceList += product;

					delete product;
				}
			}

			isFound = false;
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		bool isFound = false;

		for (size_t i = 0u; i < desc.size(); ++i)
		{
			for (size_t j = 0u; j < price.size() && !isFound; ++j)
			{
				if (desc[i].code == price[j].code)
				{
					isFound = true;

					std::unique_ptr<Product> product(new Product(desc[i].desc, price[j].price));
					product->validate();
					priceList += product;
				}
			}

			isFound = false;
		}


		return priceList;
	}
}