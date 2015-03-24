//printvisitor.cpp
//includes
#include "PrintVisitor.h"
#include "Group.h"
#include "Employee.h"
#include<iostream>
using namespace std;
//Visitor Implementation
Visitor::Visitor()=default;
Visitor::~Visitor()=default;
//PrintVisitor Implementation
PrintVisitor::PrintVisitor()=default;
PrintVisitor::~PrintVisitor()=default;
void PrintVisitor::visitGroup(Group* groupPtr) {
	groupPtr->printNode();
	indentLevel++;
	vector<Node*> nodeVector = groupPtr->getDataPtr()->getNodeVector();
	for(auto v_it = nodeVector.begin(); v_it != nodeVector.end(); v_it++) {
		Node* nodePtr = (*v_it);
	for(int x = 0; x < indentLevel; x++) {
		cout << "  ";
	}		
	nodePtr->Accept(this);
	}
	indentLevel--;
}
void PrintVisitor::visitEmployee(Employee* empPtr) {
	empPtr->printNode();
}
