#include <iostream>
#include "../secr/secr.h"
#include "../secv/secv.h"

int  main()
{
	setlocale(LC_ALL, "RU");
	int a;


	std::cout << "viberite:\n"
		<< "1. Registraciya\n"
		<< "2. Vhod\n";
	
	std::cin >> a;
	if (a == 1)
	{
		std::cout << "1\n";
		Reg::reg::reg();
	}

	else if (a == 2)
	{
		std::cout << "2\n";
	}

	return 0;
}
