#ifndef CVISIT
#define CVISIT
#include "PrintVisitor.h"
#include "Employee.h"
#include "Group.h"
class CountVisitor:public Visitor {
        public:
            void visitEmployee(Employee*);
            void visitGroup(Group*);
			void Reset();
			void PrintResults();
			CountVisitor();
            ~CountVisitor();
		private:
			int empCount=0;
			int groupCount=0;
};
#endif
