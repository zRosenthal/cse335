#ifndef PARSER_H_
#define PARSER_H_
#include<fstream>
#include<string>
//class BUIilder;
using namespace std;
class Parser {
	public:
		Parser(string);
		~Parser()=default;
		bool Parse();
	private:
		//Builder* bobTheBuilder;
		string fileName;
};
#endif
