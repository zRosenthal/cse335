#include<iostream>
#include<string>
#include<vector>
#include "SearchVisitor.h"
#include "Group.h"
#include "Employee.h"
using namespace std;
SearchVisitor::SearchVisitor() {
	query = "";
}
void SearchVisitor::Reset() {
	query = "";
	searchVector.clear();
}
void SearchVisitor::setQuery(string q) {
	query = q;
}
void SearchVisitor::visitGroup(Group* groupPtr) {
	vector<Node*> nodeVector = groupPtr->getDataPtr()->getNodeVector(); 
		
	if(groupPtr->getGroupName() == query) {
		searchVector.push_back(groupPtr);
		for(auto v_it = nodeVector.begin(); v_it < nodeVector.end(); v_it++) {
			searchVector.push_back(*v_it);
		}	
	}
	for(auto v_it = nodeVector.begin(); v_it < nodeVector.end(); v_it++) {
		(*v_it)->Accept(this);	
	}
}
void SearchVisitor::visitEmployee(Employee* empPtr) {
	string fName = empPtr->getFirstName();
	string lName = empPtr->getLastName();
	string flName = fName + " " + lName;
	if(query == flName || query == fName || query == lName) {
		searchVector.push_back(empPtr);
	}
}
void SearchVisitor::PrintResults() {
	cout << "Found " << searchVector.size() 
		 << " results for the query " << query << endl;
	bool indentOn = false;
	bool first = true;
	for(auto v_it = searchVector.begin(); v_it != searchVector.end(); v_it++) {
		if(indentOn) {cout << "  ";}
		bool trueIfGroup = (*v_it)->printNode();
		if(trueIfGroup && first ) {
			indentOn = true;
		}
		first = false;
	}
	cout << endl;
}
