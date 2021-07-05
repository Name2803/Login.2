#include "server.h"

#include <iostream>
#include <fstream>

data::data(const int outID)
{
	data::search(outID);
}

void data::search(const int outID)
{
	std::cout << "===========================\n\n";
	std::ifstream fin1;
	std::ifstream fin2;

	fin1.open(data::path1);

	if (fin1.is_open())
	{
		while (!fin1.eof())
		{
			fin1 >> data::ID >> data::password >> data::log;
			if (outID == data::ID)
			{
				system("cls");
				std::cout << "Login: " << data::log << "\n\n";
				break;
			}
		}
	}
	else
	{
		std::cout << "ERROR: Problem with file: "
			<< path1 << "\n";
	}

	fin1.close();

	fin2.open(data::path2);

	if (fin2.is_open())
	{
		while (!fin2.eof())
		{
			fin2 >> data::ID >> data::fname >> data::lname >> data::year >> data::sex >> data::status;
			if (outID == data::ID)
			{
				std::cout << "Status: " << data::status << "\n\n";
				std::cout << "Firstname: " << data::fname << "\t";
				std::cout << "Lastname: " << data::lname << "\n\n";
				std::cout << "Year: " << data::year << "\t";
				std::cout << "Sex: " << data::sex << "\n\n";
				break;
			}
		}

	}
	else
	{
		std::cout << "ERROR: Problem with file: "
			<< path2 << "\n";
	}

	fin2.close();
}

void data::anFunc()
{
	char w;
	std::cout << "Press 'y' if you wona leave: ";
	std::cin >> w;
	if (w == 'y')
		exit(1);
	
	std::cout << "another function\n";

}


