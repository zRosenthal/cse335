#include "SearchVisitor.h"
#include <iostream>
using namespace std;

SearchVisitor::SearchVisitor()
{
}

SearchVisitor::~SearchVisitor()
{
	// TODO Auto-generated destructor stub
}

void SearchVisitor::VisitGroup(Group* g)
{
    if (g->GetName()==this->mQuery) {
        //mInstancesFound++;
        mTarget.push_back(g);
        return;
    }
    else {
	for(unsigned int i = 0; i<(g->GetSize()); i++)
	{
		(g->GetItem(i))->Accept(this);
	}
    }
}

void SearchVisitor::VisitEmployee(Employee* e)
{
    if (e->GetName()==this->mQuery || e->GetLastName()==mQuery|| e->GetName()+" "+e->GetLastName()==mQuery) {
	//mTarget+=(e->GetPosition())+": "+(e->GetName())+ " " + e->GetLastName()+"\n";
        mTarget.push_back(e);  
    }
}






