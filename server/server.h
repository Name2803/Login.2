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

	const std::string path1 = "lpdata.txt";
	const std::string path2 = "data.txt";
	void showData(const int outID);
	void func1(const int fff);
};