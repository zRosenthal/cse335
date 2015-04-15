#include "Parser.h"
#include "CompanyBuilder.h"
#include<fstream>
#include <sstream>
#include<iostream>
#include<vector>
#include <time.h>  
#include <unistd.h>

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
				sleep(1); 			
				if((*v_it) == "1") {
					if(*(++v_it) == "1") {
						if(tokenVector.size() != 6) {
							system("clear");
							cout << "incorrect number of arguments for"
								 << " adding an employee" << endl;
							size_t vSize = tokenVector.size();
							v_it += vSize - 2;
						}
						else {
							string last = *(++v_it);
							string first = *(++v_it);
							string job = *(++v_it);
							string parent = *(++v_it);
							bobTheBuilder->addEmp(last,first,job,parent);
						}
					} 
					else {
						if(tokenVector.size() != 4) {
							system("clear");
							cout << "incorrect number of arguments for"
								 << " adding a group" << endl;
							size_t vSize = tokenVector.size();
							v_it += vSize - 2;	
						}
						else {
						string name = *(++v_it);
						string parent = *(++v_it);
						cout << endl;
						bobTheBuilder->addGroup(name,parent);
						}
					}	
				}
				else if(*v_it == "2") {
					if(tokenVector.size() != 2) {
						cout << "incorrect number of arguments for" 
							 << "removing a group" << endl;
						size_t vSize = tokenVector.size();
						v_it += vSize - 1;
					}
					else {
						string name = *(++v_it);
						bobTheBuilder->rmGroup(name);
					}
				}
				else if(*v_it == "3") {
					if(tokenVector.size() != 2) {
						cout << "incorrect number of arguments for "
							 << "removing a group" << endl;
						size_t vSize = tokenVector.size();
						v_it += vSize - 1;
					}
					else {	
						string name = *(++v_it);
						bobTheBuilder->disband(name);
					}
				}
				else {
					cout << "ERROR UNKNOWN INPUT: " << (*v_it) << endl;
				}
		}
	}
	bobsFile.close();
	bobTheBuilder->printCompany();
	return true;
}

