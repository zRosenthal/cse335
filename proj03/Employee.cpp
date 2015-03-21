#include<string>
using std::string; 
#include "PrintVisitor.h"
#include "Employee.h"
Employee::Employee(string f,string l,string t) {
    first = f;
    last = l;
    title = t;
}
Employee::~Employee(){}
void Employee::Accept(Visitor* visitor) {
    visitor->visitEmployee(this);
}
