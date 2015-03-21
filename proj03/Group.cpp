#include<string>
ObjectStructure::addNode(node* object ) {
    nodeVector.push(object);
}

Node::Node () { 
    
}
Node::~Node*() {
                
}
Group::Group(string n) {
    name = n;
    dataPtr = new ObjectStructure();
}
Group::~Group() {
    delete dataPtr
}
Group::Accept(Visitor* visitor) {
    visitor->visitGroup();
}
Group::AddChild(Node* node) {
    dataPtr->addNode(node);
}
