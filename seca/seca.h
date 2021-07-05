#pragma once
#include <string>

class Aut {
public:
	Aut::Aut();
private:
	std::string outLog, outPass;
	std::string inLog, inPass;
	const std::string path1 = "../server/lpdata.txt";

	int ID;
	void aut();
	bool Log();
	bool Pass();
};