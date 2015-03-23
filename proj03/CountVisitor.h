#ifndef CVISIT
#define CVISIT
#include "PrintVisitor.h"
#include "Employee.h"
#include "Group.h"
class CountVisitor:public Visitor {
        public:
            void visitEmployee(Employee*);
            void visitGroup(Group*);
			void reset();
			void printResults();
			CountVisitor();
            ~CountVisitor();
};
#endif
