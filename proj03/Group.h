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
		virtual bool printNode(int indentLevel=0)=0;
};
class ObjectStructure {
    public:
        ObjectStructure(){};
        ~ObjectStructure(){};
		vector<Node*> getNodeVector();
 		void addNode(Node*);
		int getSize();
    private:
        vector<Node*> nodeVector;
};


class Group:public Node {
    private:
        string groupName;
        ObjectStructure * dataPtr;
    public:
        Group(string);
        ~Group();
        void Accept(Visitor*);
        void AddChild(Node*);
		bool printNode(int indentLevel=0);
		ObjectStructure* getDataPtr();
		string getGroupName();
}; 
#endif
