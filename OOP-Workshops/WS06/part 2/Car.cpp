/* ------------------------------------------------------
Workshop 6: STL Container
Module: Car 
Filename: Car.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/03	Completed workshop 6 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iomanip>
#include "Car.h"

namespace sdds
{
	sdds::Car::Car(std::istream& is)
	{
		std::string str;

		// lambda function that removes the leading and trailing whitespaces
		auto removeWhitespace = [](std::string& str) -> std::string&
		{
			str.erase(0, str.find_first_not_of(' '));
			str.erase(str.find_last_not_of(' ') + 1);

			return str;
		};

		// remove the tag for the type of the vehicle
		std::getline(is, str, ',');

		// extract the name of the company that makes the car
		std::getline(is, str, ',');
		v_maker = removeWhitespace(str);

		// extract the condition of the car
		std::getline(is, str, ',');
		removeWhitespace(str);

		if (str == "n" || str == "")
		{
			v_condition = "new";
		}
		else if (str == "u")
		{
			v_condition = "used";
		}
		else if (str == "b")
		{
			v_condition = "broken";
		}
		else
		{
			throw std::string("Invalid record!");
		}

		// extract the maximum speed the vehicle can achieve
		std::getline(is, str, ','); 
		try 
		{
			v_topSpeed = std::stod(str);
		}
		catch (std::invalid_argument& error)
		{
			throw std::string("Invalid record!");
		}
	}

	std::string Car::condition() const
	{
		return this->v_condition;
	}

	double Car::topSpeed() const
	{
		return this->v_topSpeed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| " << std::setw(10) << this->v_maker << " | ";
		out << std::setw(6) << std::left << this->condition() << std::right << " | ";
		out << std::setw(6) << std::fixed << std::setprecision(2) << this->topSpeed() << " |";
	}
}
