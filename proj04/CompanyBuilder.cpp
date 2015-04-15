#include "Group.h"
#include "Employee.h"
#include "SearchVisitor.h"
#include "PrintVisitor.h"
#include "CompanyBuilder.h"
#include "Group.h"
#include<string>
#include<vector>
#include<iostream>
#include<cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;
void CompanyBuilder::createCompany(string name) {
	root = new Group(name);
	sVisitor = new SearchVisitor();
	pVisitor = new PrintVisitor();
	printCompany();
}
void CompanyBuilder::printCompany() {
	system("clear");
	sleep(2);
	root->Accept(pVisitor);
}

CompanyBuilder::~CompanyBuilder() {
	delete root;
	delete sVisitor;
	delete pVisitor;
}
bool CompanyBuilder::addEmp(string l,string f, string j, string p) {
	sVisitor->setQuery(p);
	root->Accept(sVisitor);
	if(sVisitor->getVecSize() == 0) {
		system("clear");
		cout << "Invalid Parent '"<< p <<"' - The parent group you specified does not exist" << endl;
		return false;
	}
	Node* parent = sVisitor->getFirstElement();
	sVisitor->Reset();
	Employee* emp = new Employee(f,l,j,parent);
	parent->AddChild(emp);
	system("clear");
	sleep(1);
	root->Accept(pVisitor);
	return true;
}
bool CompanyBuilder::addGroup(string n, string p) {
	if(n == p) {
		cout << "cannot add group '" << n<< "' to itself" <<endl;
	}
	sVisitor->setQuery(p);
	root->Accept(sVisitor);
	if(sVisitor->getVecSize() == 0) {
		system("clear");
		cout << "Invalid Parent '" << p << "' - The parent group you specified does not exist" << endl;
		return false;
	}
	Node* parent = sVisitor->getFirstElement();
	sVisitor->Reset();
	Group* group = new Group(n,parent);
	parent->AddChild(group);
	system("clear");
	sleep(1);
	root->Accept(pVisitor);

	return true;
}

bool CompanyBuilder::disband(string n) {
	sVisitor->setQuery(n);
	cout << "n: " << n << endl;
	root->Accept(sVisitor);
	if(sVisitor->getVecSize() == 0) {
		system("clear");
		cout << "Invalid Group '" << n <<"' - The Group you specified does not exist" << endl;
		return false;
	}
	Node* group = sVisitor->getFirstElement();
	sVisitor->Reset();
	Node* parent = group->getParent();	
	
	vector<Node*> nodeVector = group->getDataPtr()->getNodeVector();
	for(auto v_it = nodeVector.begin(); v_it != nodeVector.end();v_it++) {
		parent->AddChild(*v_it);
	}
	parent->getDataPtr()->remove(group);	
	system("clear");
	
	sleep(1);
	root->Accept(pVisitor);	
}
bool CompanyBuilder::rmGroup(string n) {
	sVisitor->setQuery(n);
	root->Accept(sVisitor);
	if(sVisitor->getVecSize() == 0) {
		system("clear");
		cout << "Invalid Group '" << n << "' - The Group you specified does not exist" << endl;
		return false;
	}
	Node* group = sVisitor->getFirstElement();
	sVisitor->Reset();
	Node* parent = group->getParent();
	parent->getDataPtr()->remove(group);
	delete group;
	system("clear");
	sleep(1);
	root->Accept(pVisitor);
	return true;
}

Node* CompanyBuilder::getResult() {
	return root;
}
