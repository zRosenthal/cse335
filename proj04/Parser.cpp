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
		}
		for(auto v_it = tokenVector.begin(); v_it != tokenVector.end(); v_it++) {
				if((*v_it) == "1") {
					if(*(++v_it) == "1") {
						cout << endl << endl;
						string last = *(++v_it);
						string first = *(++v_it);
						string job = *(++v_it);
						string parent = *(++v_it);
						bobTheBuilder->addEmp(last,first,job,parent);
					} 
					else {
						cout << "wtf" << endl;
						string name = *(++v_it);
						string parent = *(++v_it);
						cout << endl;
						cout << "name: " << name << " parent " << parent << endl;
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

