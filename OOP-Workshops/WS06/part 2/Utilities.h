/* ------------------------------------------------------
Workshop 6: STL Container
Module: Utilities 
Filename: Utilities.h
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
#ifndef SDDS_UTILITIES_H
#define	SDDS_UTILITIES_H

#include <iostream>
#include "Vehicle.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}
#endif // !SDDS_UTILITIES_H
