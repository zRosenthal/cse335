#include<string>
#include<iostream>
using std::string; 
#include "PrintVisitor.h"
#include "Employee.h"
Employee::Employee(string f,string l,string t) {
    firstName = f;
    lastName = l;
    jobTitle = t;
}
Employee::~Employee(){}
void Employee::Accept(Visitor* visitor) {
    visitor->visitEmployee(this);
}
bool Employee::printNode(int indentLevel) {
	for(int i=0; i < indentLevel; i++) {
		cout << "  ";
	}
	cout << jobTitle << ": " << firstName << " "<< lastName << endl;
	return false;
}
