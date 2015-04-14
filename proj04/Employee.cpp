#include<string>
#include<iostream>
using std::string; 
#include "PrintVisitor.h"
#include "Employee.h"
class Group;
string Employee::getGroupName() {
	string str = firstName + " " + lastName;
	return str;
}
Employee::Employee(string f,string l,string t, Node* p) {
    firstName = f;
    lastName = l;
    jobTitle = t;
	parent = p;
}
Node* Employee::getParent() { return parent;}
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
string Employee::getFirstName() {
	return firstName;
}
string Employee::getLastName() {
	return lastName;
}
string Employee::getJobTitle() {
	return jobTitle;
}
