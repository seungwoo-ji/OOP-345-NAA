/* ------------------------------------------------------
Workshop 5: Functions and Error Handling
Module: Collection
Filename: Collection.h
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/10/28	Completed workshop 5 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

namespace sdds
{
	template <typename T>
	class Collection
	{
		std::string c_name;
		T* c_items{};
		size_t c_size{ 0u };

		void (*observer)(const Collection<T>&, const T&) { nullptr };

	public:
		Collection(std::string name) { this->c_name = name; }
		Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;
		~Collection()
		{
			if (this->c_items != nullptr)
			{
				delete[] this->c_items;
				this->c_items = nullptr;
			}
		}

		const std::string& name() const
		{
			return this->c_name;
		}

		size_t size() const
		{
			return this->c_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			this->observer = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool isFound = false;

			for (size_t i = 0u; i < this->c_size && !isFound; ++i) // if the size = 0u, the for loop would not be executed and hence, prevent dereferencing the nullptr
			{
				isFound = this->c_items[i].title() == item.title();
			}

			if (!isFound) // if the item is not found 
			{
				T* temp = new T[this->c_size + 1];

				for (size_t i = 0u; i < this->c_size; ++i)
				{
					temp[i] = this->c_items[i];
				}

				temp[this->c_size++] = item;

				delete[] this->c_items;
				this->c_items = new T[this->c_size];

				for (size_t i = 0u; i < this->c_size; ++i)
				{
					this->c_items[i] = temp[i];
				}

				delete[] temp;

				if (this->observer != nullptr) // if an observer has been registered, call it
				{
					this->observer(*this, item);
				}
			}

			return*this;
		}

		T& operator[](size_t idx) const
		{
			if (idx >= this->c_size)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(this->c_size) + "] items.");
			}

			return this->c_items[idx];
		}

		T* operator[](std::string title) const
		{
			bool isFound = false;
			size_t idx = 0u;

			for (size_t i = 0u; i < this->c_size && !isFound; ++i)
			{
				isFound = this->c_items[i].title() == title;
				idx = i;
			}

			return isFound ? &this->c_items[idx] : nullptr;
		}
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection)
	{
		for (size_t i = 0u; i < collection.size(); ++i)
		{
			os << collection[i];
		}

		return os;
	}
}
#endif // !SDDS_COLLECTION_H
