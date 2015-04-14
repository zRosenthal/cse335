#include "Parser.h"
#include<fstream>
#include <sstream>
#include<iostream>
using namespace std;
Parser::Parser(string fName) {
	fileName = fName;	
}
bool Parser::Parse() {
	//bobTheBuilder = builder;
	//parse file
	cout << "tell me somehting" << endl;
	string line;
	char token[256];
	size_t index =0;
	size_t secondindex;
	ifstream bobsFile;
	bobsFile.open(fileName); 
	bool is = bobsFile.is_open();
		
	while(getline(bobsFile, line) ) {
		stringstream buffer(line);
		while(buffer.getline(token,256,',')) {
			cout << "token: " << token << endl;
		}
	}
	return true;
}

