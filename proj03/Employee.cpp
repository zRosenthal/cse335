#include<string>
using std::string; 
#include "PrintVisitor.h"
#include "Employee.h"
Employee::Employee(string f,string l,string t) {
    fist = f;
    last = l;
    title = t;
}
Employee::~Employee(){}
Employee::Accept(Visitor* visitor) {
    visitor->visitEmployee();
}
