#ifndef GROUP
#define GROUP

class Visitor;
#include<string>
#include<vector>
using namespace std;
#include "Group.h"
//#include "PrintVisitor.h"
class Node {
    public:
        Node();
        ~Node();
        virtual void Accept(Visitor*)=0;
};
class ObjectStructure {
    public:
        ObjectStructure(){};
        ~ObjectStructure(){};
        void addNode(Node*);
    private:
        vector<Node*> nodeVector;
};


class Group:public Node {
    private:
        string name;
        ObjectStructure * dataPtr;
    public:
        Group(string);
        ~Group();
        void Accept(Visitor*);
        void AddChild(Node*);
}; 
#endif
