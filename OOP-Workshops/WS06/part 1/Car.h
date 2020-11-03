#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string v_maker;
		std::string v_condition;
		double v_topSpeed{ 0.0 };

	public:
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_CAR_H
