#include "server.h"

#include <iostream>
#include <fstream>

data::data(const int outID)
{
	data::showData(outID)
}
void data::showData(const int outID)
{
	char p;

	std::ifstream fin;
	fin.open(path2);
	if (fin.is_open())
	{
		while (fin.eof())
		{
			fin >> data::ID >> data::fname >> data::lname >> data::year >> data::sex >> data::status;

		}
	}
	else
	{
		std::cout << "ERROR: problem with file!\n"
			<< data::path1 << std::endl;
		exit(1);
	}

	fin.close();

	std::cout << "If you want exit, press 'y': ";
}