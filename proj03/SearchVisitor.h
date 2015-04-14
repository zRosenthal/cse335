/*
 * SearchVisitor.h
 *
 *  Created on: Jan 16, 2011
 *      Author: student
 */

#ifndef SEARCHVISITOR_H_
#define SEARCHVISITOR_H_

#include "Visitor.h"
#include <iostream>
class SearchVisitor: public Visitor
{
public:
	SearchVisitor();
        void setQuery(std::string query) {mQuery=query;}
        void Reset() {mQuery=""; mInstancesFound=0; mTarget.clear();}
        void PrintResults() {
            std::cout << "Found " << mTarget.size() << " results for the query " << mQuery << std::endl;
        for (int i=0; i<mTarget.size(); i++) {
            mTarget[i]->Print();
        }
        std::cout << std::endl;}
        SearchVisitor(const SearchVisitor &v)=default;
        SearchVisitor& operator=(const SearchVisitor &rhs)=default;
	virtual ~SearchVisitor();
	virtual void VisitGroup(Group* g);
	virtual void VisitEmployee(Employee* e);

private:
        int mInstancesFound=0;
        std::string mQuery;
        std::vector<Node*> mTarget;
};

#endif /* SEARCH_VISITOR_H_ */
