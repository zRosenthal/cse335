#ifndef GROUP
#define GROUP
#include "Group.h"
#include "PrintVisitor.h"
#include<string>
#include<vector>
using namespace std;
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
