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
        string first;
        string last;
        string title;
    public:
        Employee(string,string,string);
        ~Employee();
        void Accept(Visitor* visitor);
};
#endif
