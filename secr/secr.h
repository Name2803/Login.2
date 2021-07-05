#pragma once
#include <string>

namespace Reg
{
	class reg {
	public:
		reg::reg();

	private:
		std::string fname, lname, year, sex, status;
		std::string log, pass, confPass, inLog;
		int ID = 0;

		const std::string path1 = "../server/lpdata.txt";
		const std::string path2 = "../server/data.txt";
		void funk1();
		int login();
		int password();
		void wr();
	};
}
