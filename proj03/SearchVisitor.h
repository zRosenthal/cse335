#ifndef SVISIT
#define SVISIT
#include<string>
#include "PrintVisitor.h"
class Node;
class Employee;
class Group;
using namespace std;
class SearchVisitor:public Visitor {
        public:
			void Reset();
			void setQuery(string);
            SearchVisitor();
            ~SearchVisitor();
			void visitEmployee(Employee*);
			void visitGroup(Group*);
			void PrintResults();
		private:
			string query;
			vector<Node*> searchVector; 
			
};
#endif
