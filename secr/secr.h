#pragma once
#include <string>

namespace Reg
{
	class reg {
	public:
		reg::reg();

	private:
		std::string fname, lname, year, sex, status;
		std::string inLog, log, password;
		int ID;
		std::string tamp;

		const std::string path1 = "../server/lpdata.txt";
		const std::string path2 = "../server/data.txt";

		void funk1();
		int login();
		int pass();
		void server();
	};
}
