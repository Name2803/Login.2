#pragma once
#include <string>

class data
{
public:
	data(const int outID);
private:
	std::string fname, lname, year, sex, status;
	std::string log, password;
	int ID;
	std::string tamp;
	std::string path1 = "../server/lpdata.txt";
	std::string path2 = "../server/data.txt";
	

	void search(const int outID);
	void anFunc();
};