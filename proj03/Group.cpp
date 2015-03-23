#include<string>
#include<iostream>
using namespace std;
#include "Group.h"
#include "PrintVisitor.h"
void ObjectStructure::addNode(Node* object ) {
	nodeVector.push_back(object);
}
Node* ObjectStructure::getNodePtr(int index) {
	return nodeVector[index];
}
int ObjectStructure::getSize() {
	return nodeVector.size();
}

Node::Node () { 
    
}
Node::~Node() {
                
}
Group::Group(string n) {
    groupName = n;
    dataPtr = new ObjectStructure();
}
Group::~Group() {
    delete dataPtr;
}
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
ObjectStructure* Group::getDataPtr() {
	return dataPtr;
}
