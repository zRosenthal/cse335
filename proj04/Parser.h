#ifndef PARSER_H_
#define PARSER_H_
#include<fstream>
#include<string>
class CompanyBuilder;
using namespace std;
class Parser {
	public:
		Parser(string);
		~Parser()=default;
		bool Parse(CompanyBuilder*);
	private:
		CompanyBuilder* bobTheBuilder;
		string fileName;
};
#endif
