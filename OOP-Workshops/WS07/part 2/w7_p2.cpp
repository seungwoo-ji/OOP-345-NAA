/* ------------------------------------------------------
Workshop 7: STL Algorithms
Module: w7_p2
Filename: w7_p2.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/10	Completed workshop 7 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "SongCollection.h"
#include "SongCollection.h"


void printbar(std::ostream& out = std::cout)
{
	out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
}

void printHeader(const char* title, std::ostream& out = std::cout)
{
	printbar(out);
	out << "| " << std::left << std::setw(85) << title << std::right << "|\n";
	printbar(out);
}

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::SongCollection theCollection(argv[1]);

	printHeader("The original collection");
	theCollection.display(std::cout);
	printbar();

	
	printHeader("The collection sorted by title");
	theCollection.sort("title");
	theCollection.display(std::cout);
	printbar();

	printHeader("The collection sorted by length");
	theCollection.sort("title");
	theCollection.sort("length");
	theCollection.display(std::cout);
	printbar();


	printHeader("The collection with fixed album names");
	theCollection.cleanAlbum();
	theCollection.display(std::cout);
	printbar();

	{
		// looking for "The Beatles" in the collection
		if (theCollection.inCollection("The Beatles"))
			std::cout << "There are songs of \"The Beatles\" in collection.\n";
		else
			std::cout << "There are no songs of \"The Beatles\" in collection.\n";
	}

	{
		// look for Sia; increase the price of each song by 5 cents
		if (theCollection.inCollection("Sia"))
		{
			printHeader("Songs of \"Sia\"");
			auto sia = theCollection.getSongsForArtist("Sia");
			for (auto& song : sia)
			{
				std::cout << song << "\n";
				song.m_price += 10;
			}
			printbar();
		}
	}
}