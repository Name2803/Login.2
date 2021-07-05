#include "secr.h"
#include "../server/server.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

//#define DEBUG

namespace Reg
{
	reg::reg()
	{
#ifndef DEBUG
		system("cls");
#endif // !DEBUG
		funk1();
	}

	void reg::funk1()
	{
		std::cout << "Firstname: ";
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
			std::cout << "This username is already occupet!\n"
				<< "Please try again\n";
		}

		system("cls");

		while (reg::password())
		{
			system("cls");
			std::cout << "Couldn't confirm password!\n"
				<< "Please try again\n";
		}

		reg::wr();

		data::data(reg::ID);
	}

	int reg::login()
	{
		std::ifstream fin;

		std::cout << "=======Part_2=======\n"
			<< "\nLogin: ";
		std::cin >> reg::log;

		fin.open(path1);
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				fin >> reg::ID >> reg::inLog >> reg::inLog;
#ifdef DEBUG
				_sleep(2000);
				std::cout  << reg::ID  << " " << reg::inLog << "\n";
#endif // DEBUG
				if (reg::log == reg::inLog)
					return 1;
			}
			return 0;
		}
		else
		{
			std::cout << "\n------!there was problem with the file!------\n"
			<< path1 << std::endl;
			exit(1);
		}
		fin.close();


		return 0;
	}

	int reg::password()
	{
		std::cout << "=======Part_2=======\n"
			<< "\nPassword: ";
		std::cin >> reg::pass;
		std::cout << "Confirm your password: ";
		std::cin >> reg::confPass;
		if (reg::pass == reg::confPass)
			return 0;
		return 1;
	}

	void reg::wr()
	{
		std::ofstream fout1;
		fout1.open(reg::path1, std::ofstream::app);

		std::ofstream fout2;
		fout2.open(reg::path2, std::ofstream::app);

		if (!fout1.is_open())
		{
			std::cout << "\n------!there was problem with the file!------\n"
				<< reg::path1 << std::endl;
			exit(1);
		}
		else
		{
			reg::ID++;
			fout1 << reg::ID << " " << reg::pass << " " << reg::log << "\n";
		}
		if (!fout2.is_open())
		{
			std::cout << "\n------!there was problem with the file!------"
				<< reg::path2 << std::endl;
			exit(1);
		}
		else
			fout2 << reg::ID << reg::fname << " " << reg::lname << " " << reg::year << " " << reg::sex << " " << reg::status << "\n";

		fout1.close();
		fout2.close();
	}


}
			