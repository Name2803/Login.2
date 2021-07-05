#include <iostream>
#include "../secr/secr.h"
#include "../seca/seca.h"

int  main()
{
	setlocale(LC_ALL, "RU");
	int a;


	std::cout << "viberite:\n"
		<< "1. Registraciya\n"
		<< "2. Vhod\n";
	
	std::cin >> a;
	if (a == 1)
		Reg::reg::reg();

	else if (a == 2)
		Aut::Aut();

	return 0;
}
