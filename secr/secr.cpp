#include "secr.h"
#include "../server/server.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

#define DEBUG

namespace Reg
{

	reg::reg()
	{
		reg::funk1();
	}
	void reg::funk1()
	{
		system("cls");
		std::cout << "======Registration======\n";
		std::cout << "\nFirstname: ";
		std::cin >> reg::fname;
		std::cout << "\nLastname: ";
		std::cin >> reg::lname;
		std::cout << "\nYear: ";
		std::cin >> reg::year;
		std::cout << "\nSex: ";
		std::cin >> reg::sex;
		std::cout << "\nStatus: ";
		std::cin >> reg::status;

		system("cls");
		while (reg::login())
		{
			system("cls");
			std::cout << "This login is already in use!\n"
				<<"Please try again\n";
		}

		while (reg::pass())
		{
			system("cls");
			std::cout << "Wrong!\n"
				<< "Please try again\n";
		}

		system("cls");
		std::cout << "\n\n\n\n"
			<< "====Registration was successful!===="
			<< "\n\n\n\n";



		reg::server();

		data::data(reg::ID);
	}

	int reg::login()
	{
		std::ifstream fin;
		std::cout << "Login:\n";
		std::cin >> log;

		fin.open(path1);
		if (fin.is_open())
		{
			fin.seekg(0, std::ios::end);
			if (fin.tellg() == 0)
			{
				reg::ID = 0;
				return 0;
			}
			else
			{
				while (!fin.eof())
				{
					fin >> reg::ID >> reg::inLog >> reg::inLog;

					std::cout << reg::ID << "  " << reg::inLog << "\n";

					if (sizeof(reg::inLog) != sizeof(reg::log))
					{
						std::cout << "\nRight\n";
						continue;
					}
					else
					{
						for (int i = 0; i < (sizeof(reg::log) / 8 - 1); i++)
						{
							if (reg::inLog[i] == reg::log[i])
								if (i == sizeof(reg::log) / 8 - 2)
									return 1;
							else
								break;
						}
					}
				}
			}

		}
		else
		{
			std::cout << "ERROR: problem with file!\n"
				<< reg::path1 << std::endl;
			exit(1);
		}
		
		return 0;
	}

	int reg::pass()
	{
		std::cout << "\nPassword: ";
		std::cin >> reg::password;

		std::cout << "\nConfirm it: ";
		std::cin >> reg::tamp;

		if (sizeof(reg::password) != sizeof(reg::tamp))
			return 1;
		else
		{
			for (int i = 0; i < sizeof(reg::password) / 8 - 2; i++)
				if (reg::password[i] != reg::tamp[i])
					return 1;
			return 0;
		}
	}

	void reg::server()
	{
		std::ofstream fout;
		fout.open(reg::path1, std::ofstream::app);
		if(fout.is_open())
			fout << ++reg::ID << " " << reg::password << " " << reg::log << "\n";
		else
		{
			std::cout << "ERROR: problem with file!\n"
				<< reg::path1 << std::endl;
			exit(1);
		}
		fout.close();

		fout.open(reg::path2, std::ofstream::app);
		if(fout.is_open())
			fout << reg::ID << " " << reg::fname << " " << reg::lname << " " << reg::year << " " << reg::sex << " " << reg::status << "\n";
		else
		{
			std::cout << "ERROR: problem with file!\n"
				<< reg::path2 << std::endl;
			exit(1);
		}
		fout.close();
	}
}