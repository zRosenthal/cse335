#ifndef SVISIT
#define SVISIT
#include<string>
#include "PrintVisitor.h"
using namespace std;
class SearchVisitor:public Visitor {
        public:
			void reset();
			void setQuery(string);
            SearchVisitor();
            ~SearchVisitor();
			void visitEmployee(Employee*);
			void visitGroup(Group*);
		private:
			string query;
};
#endif
