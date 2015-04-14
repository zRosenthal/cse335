#ifndef EMP_H_
#define EMP_H_
//forward declerations
class Visitor;
//includes
#include<string>
#include "Group.h"
using namespace std;
//Employee class header
class Employee:public Node {
    private:
        string firstName;
        string lastName;
        string jobTitle;
		Node* parent;
	public:
        Employee(string,string,string,Node*);
		~Employee()=default;
		Employee& operator=(const Employee&)=default;
		Employee(const Employee&)=default;
        void Accept(Visitor* visitor);
		bool printNode(int indentLevel=0);
		string getFirstName();
		string getLastName();
		string getJobTitle();
		string getGroupName();
		Node* getParent();
};
#endif
