#include "PrintVisitor.h"
#include <iostream>
using namespace std;


PrintVisitor::~PrintVisitor()
{
	// TODO Auto-generated destructor stub
}

void PrintVisitor::VisitGroup(Group* g)
{
	PrintIndent();
	cout<<g->GetFormatName()<<endl;

	if(g->GetSize()>0)mIndent+=2;

	for(unsigned int i = 0; i<(g->GetSize()); i++)
	{
		(g->GetItem(i))->Accept(this);
	}
}



void PrintVisitor::VisitEmployee(Employee* e)
{
	PrintIndent();
	cout<<e->GetFormatName()<<endl;
}

void PrintVisitor::PrintIndent()
{
	for(int i = 0; i<mIndent; i++)
	{
		cout<<" ";
	}
}






