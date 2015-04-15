#ifndef GROUP
#define GROUP
class Visitor;
#include<string>
#include<vector>
using namespace std;
//#include "PrintVisitor.h"
class ObjectStructure;
class Node {
    public:
        Node() {};
        virtual ~Node() {};
		Node& operator=(const Node &)=default;
		Node(const Node &)=default;
        virtual void Accept(Visitor*)=0;
		virtual bool printNode(int indentLevel=0)=0;
		virtual Node* getParent()=0;
		virtual void AddChild(Node*) {}
		virtual ObjectStructure* getDataPtr() {}
		virtual string getGroupName() {}
};
class ObjectStructure {
    public:
        ObjectStructure(){};
        ~ObjectStructure()=default;
		ObjectStructure& operator=(const ObjectStructure&)=default;
		ObjectStructure(const ObjectStructure&)=default;
		vector<Node*> getNodeVector();
 		void addNode(Node*);
		int getSize();
		void remove(Node*);
	private:
        vector<Node*> nodeVector;
};


class Group:public Node {
    private:
        string groupName;
        ObjectStructure * dataPtr;
		Node* parent;
	public:
        Group(string,Node*);
		Group(string);
        ~Group();
		Group& operator=(const Group&)=default;
		Group(const Group&)=default;
        void Accept(Visitor*);
        void AddChild(Node*);
		bool printNode(int indentLevel=0);
		ObjectStructure* getDataPtr();
		string getGroupName();
		Node* getParent();
}; 
#endif
