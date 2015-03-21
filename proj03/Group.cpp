#include<string>
#include "Group.h"
#include "PrintVisitor.h"
void ObjectStructure::addNode(Node* object ) {
    nodeVector.push_back(object);
}

Node::Node () { 
    
}
Node::~Node() {
                
}
Group::Group(string n) {
    name = n;
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
