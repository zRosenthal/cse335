//printvisitor.cpp
//includes
#include "PrintVisitor.h"
#include "Group.h"
#include<iostream>
//Visitor Implementation
Visitor::Visitor() {}
Visitor::~Visitor()=default;
//PrintVisitor Implementation
PrintVisitor::PrintVisitor() {}
PrintVisitor::~PrintVisitor()=default;
void PrintVisitor::visitGroup(Group* groupPtr) {
	if(!indentLevel) {
		groupPtr->printNode();
		indentLevel++;
	}
	int structurSize = groupPtr->getDataPtr()->getSize();
	for(int i = 0; i < structurSize; i++) {
		Node* nodePtr = groupPtr->getDataPtr()->getNodePtr(i);
		bool trueIfGroup = nodePtr->printNode(indentLevel);
		if(trueIfGroup) {
			indentLevel++;
			nodePtr->Accept(this);
			indentLevel--;
		}
	}
}
void PrintVisitor::visitEmployee(Employee* empPtr) {}
