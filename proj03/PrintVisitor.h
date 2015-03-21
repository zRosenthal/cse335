#ifndef PVISIT_H_
#define PVISIT_H_
#include "Employee.h"
#include "Group.h"
class Visitor {
    public:
        virtual void visitEmployee(Employee*)=0;
        virtual void visitGroup(Group*)=0;
        Visitor();
        ~Visitor();
};
class PrintVisitor:public Visitor {
    public:
        PrintVisitor();
        ~PrintVisitor();
        void visitEmployee(Employee*);
        void visitGroup(Group*);
};
#endif
