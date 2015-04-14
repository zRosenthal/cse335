#include<string>
#include<iostream>
using namespace std;
#include "Group.h"
#include "PrintVisitor.h"
void ObjectStructure::addNode(Node* object ) {
	nodeVector.push_back(object);
}
vector<Node*> ObjectStructure::getNodeVector() {
	return nodeVector;
}
int ObjectStructure::getSize() {
	return nodeVector.size();
}
void ObjectStructure::remove(Node* n) {
	string name = n->getGroupName();
	size_t index = 0;
	for(auto i = nodeVector.begin();i!=nodeVector.end();i++) {
		index++;
		string name2 = (*i)->getGroupName();
		if(name2 == name) {
			break;
		}
	}
	index--;
	nodeVector.erase(nodeVector.begin()+index);
}
Node* Group::getParent() {return parent;}
Group::Group(string n, Node* p) {
    parent = p;
	groupName = n;
    dataPtr = new ObjectStructure();
}
Group::Group(string name) {
	groupName = name;
	dataPtr = new ObjectStructure();
}
Group::~Group() {
    vector<Node*> nvec = dataPtr->getNodeVector();
	for(auto it = nvec.begin(); it!=nvec.end(); it++) {
		delete *it;
	}
	delete dataPtr;
}/*
void Group::remove(Node*) {
	vector<node*> v = dataPtr->getNodeVe
}*/
void Group::Accept(Visitor* visitor) {
    visitor->visitGroup(this);
}
void Group::AddChild(Node* node) {
	dataPtr->addNode(node);
}
bool Group::printNode(int indentLevel) {
	for(int i = 0; i < indentLevel; i++) {
		cout << "  ";
	}
	cout << "+ Team " << groupName << endl;
	return true;
}
string Group::getGroupName() {
	return groupName;
}
ObjectStructure* Group::getDataPtr() {
	return dataPtr;
}
