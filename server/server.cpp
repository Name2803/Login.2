#include "server.h"

#include <iostream>
#include <fstream>

data::data(const int outID)
{
	data::searchData(outID);
}

void data::searchData(const int outID)
{
	char p;

	std::ifstream fin;
	fin.open(path2);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> data::ID >> data::fname >> data::lname >> data::year >> data::sex >> data::status;
			if (outID == data::ID)
			{
				data::showData();
				break;
			}
			
		}
		std::cout << "ERROR: data is not right!\n"
			<< data::path2 << std::endl;
	}
	else
	{
		std::cout << "ERROR: problem with file!\n"
			<< data::path2 << std::endl;
		exit(1);
	}

	fin.close();

	std::cout << "If you want exit, press 'y': ";
}

void data::showData()
{
	std::cout << data::ID << std::endl;
	std::cout << data::fname << std::endl;
	std::cout << data::lname << std::endl;
	std::cout << data::year << std::endl;
	std::cout << data::sex << std::endl;
	std::cout << data::status << std::endl;
}
