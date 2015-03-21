#ifndef EMP_H_
#define EMP_H_
#include<string>
#include "PrintVisitor.h"
#include "Group.h"
using namespace std;
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
