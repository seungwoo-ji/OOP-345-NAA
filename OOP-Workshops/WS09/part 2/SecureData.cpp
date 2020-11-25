/* ------------------------------------------------------
Workshop 9: Multi-Threading
Module: SecureData
Filename: SecureData.cpp
Version: 1.0
Author: Seung Woo Ji
Student Number: 116376195
Email: swji1@myseneca.ca
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/20	Completed workshop 9 part 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		auto convertText1 = std::bind(converter, text, key, (nbytes / 2), Cryptor());
		auto convertText2 = std::bind(converter, text + (nbytes / 2), key, (nbytes / 2), Cryptor()); // increments the pointer of the text by the half of nbytes
	
		std::thread thread1(convertText1);
		std::thread thread2(convertText2);

		thread1.join();
		thread2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			std::fstream binaryFile(file, std::ios::out | std::ios::binary | std::ios::trunc);

			// TODO: write data into the binary file
			//         and close the file	
			binaryFile.write(this->text, this->nbytes);

			binaryFile.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::fstream binaryFile(file, std::ios::in | std::ios::binary);
		
		if (!binaryFile)
		{
			throw string("\n***Failed to open file ") +
				string(file) + string(" ***\n");
		}

		// deallocate the pre-owned memory if existed
		if (text)
		{
			delete[] this->text;
			this->nbytes = 0;
		}
		
		// TODO: - allocate memory here for the file content
		binaryFile.seekg(0, std::ios::end);
		this->nbytes = (int)binaryFile.tellg();
	
		this->text = new char[this->nbytes];

		// TODO: - read the content of the binary file
		binaryFile.seekg(std::ios::beg);
		binaryFile.read(this->text, this->nbytes);

		binaryFile.close();
		
		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
