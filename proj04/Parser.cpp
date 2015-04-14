#include "Parser.h"
#include "CompanyBuilder.h"
#include<fstream>
#include <sstream>
#include<iostream>
#include<vector>
using namespace std;
Parser::Parser(string fName) {
	fileName = fName;	
}
bool Parser::Parse(CompanyBuilder* builder) {
	bobTheBuilder = builder;
	//parse file
	string line;
	char token[256];
	ifstream bobsFile;
	bobsFile.open(fileName); 
	getline(bobsFile, line);
	string str(line);
	bobTheBuilder->createCompany(str);
	while(getline(bobsFile, line) ) {
		stringstream buffer(line);
		vector<string> tokenVector;
		while(buffer.getline(token,256,',')) {
			tokenVector.push_back(token);
			cout << token << endl;
		}
		for(auto v_it = tokenVector.begin(); v_it != tokenVector.end(); v_it++) {
				if((*v_it) == "1") {
					if(*(++v_it) == "1") {
						string last = *(++v_it);
						string first = *(++v_it);
						string job = *(++v_it);
						string parent = *(++v_it);
						cout << "before addEmp" << endl;
						bobTheBuilder->addEmp(last,first,job,parent);
						cout << "after addEmp" << endl;
					} 
					else {
						string name = *(++v_it);
						string parent = *(++v_it);
						bobTheBuilder->addGroup(name,parent);
					}	
				}
				else if(*v_it == "2") { 
					string name = *(++v_it);
					bobTheBuilder->rmGroup(name);
				}
				else if(*v_it == "3") {
					string name = *(++v_it);
					bobTheBuilder->disband(name);
				}
				else {
					cout << "ERROR OOOHH NO";
				}
		}
	}
	return true;
}

