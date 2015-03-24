#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include "CountVisitor.h"
CountVisitor::CountVisitor()=default;
CountVisitor::~CountVisitor()=default;
void CountVisitor::visitGroup(Group* groupPtr) {
	groupCount++;
	vector<Node*> nodeVector = groupPtr->getDataPtr()->getNodeVector();
	for(auto v_it = nodeVector.begin(); v_it != nodeVector.end();v_it++){
		(*v_it)->Accept(this);	
	}
}
void CountVisitor::visitEmployee(Employee*) {
	empCount++;
}
void CountVisitor::Reset() {
	groupCount = 0;
	empCount = 0;
}
void CountVisitor::PrintResults() {
	cout << "Number of Groups: " << groupCount << endl;
	cout << "Number of Employees: " << empCount << endl;
}
