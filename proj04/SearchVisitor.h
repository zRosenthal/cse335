#ifndef SVISIT
#define SVISIT
#include<string>
#include<vector>
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
			SearchVisitor& operator=(const SearchVisitor&)=default;
			SearchVisitor(const SearchVisitor&)=default;
            ~SearchVisitor()=default;
			void visitEmployee(Employee*);
			void visitGroup(Group*);
			void PrintResults();
			Node* getFirstElement();
			int getVecSize();
		private:
			string query;
			vector<Node*> searchVector; 
			
};
#endif
