#include "seca.h"
#include <iostream>
#include <fstream>
#include "../server/server.h"

Aut::Aut()
{
	Aut::aut();
}

void Aut::aut()
{
	system("cls");

	while (!Aut::Log())
	{
		system("cls");
		std::cout << "The username does not exist\n"
			<< "Try again\n";
	}
	
	data::data(Aut::ID);
}

bool Aut::Log()
{
	std::ifstream fin1;
	std::cout << "======Autorithation======\n\n";
	std::cout << "Login: ";
	std::cin >> Aut::outLog;

	fin1.open(Aut::path1);
	if (fin1.is_open())
	{
		while (!fin1.eof())
		{
			fin1 >> Aut::ID >> Aut::inPass >> Aut::inLog;
			if (Aut::inLog == Aut::outLog)
			{
				system("cls");
				while (!Aut::Pass())
				{
					system("cls");
					std::cout << "Incorrect password!\n"
						<< "Try again\n";
				}
				return true;
			}
		}
	}
	else
	{
		std::cout << "\n------!there was problem with the file!------\n"
			<< Aut::path1 << std::endl;
		exit(1);
	}
}

bool Aut::Pass()
{
	std::cout << "======Autorithation======\n\n";
	std::cout << "Password: ";
	std::cin >> Aut::outPass;

	if (Aut::outPass == Aut::inPass)
		return true;
	else
		return false;
}