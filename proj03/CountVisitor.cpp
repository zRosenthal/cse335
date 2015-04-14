#include "CountVisitor.h"
#include <iostream>
using namespace std;


CountVisitor::~CountVisitor()
{
	// TODO Auto-generated destructor stub
}

void CountVisitor::VisitGroup(Group* g)
{
    mGroupCount++;
    for(unsigned int i = 0; i<(g->GetSize()); i++)
    {
            (g->GetItem(i))->Accept(this);
    }
}



void CountVisitor::VisitEmployee(Employee* e)
{
    mEmployeeCount++;
}





