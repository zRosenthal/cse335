#include "Group.h"
#include "Visitor.h"
#include <iostream>
using namespace std;

Group::Group(const string &name) : Node(name)
{

}

Group::~Group()
{
	while(!mList.empty())
	{
		delete mList.back();
		mList.pop_back();
	}
}


void Group::Print()
{
	cout<<GetFormatName()<<endl;
	for(int i = 0; i<mList.size(); i++)
	{
		cout<<"  "<<mList[i]->GetFormatName()<<endl;
	}
}

void Group::AddChild(Node *child)
{
	mList.push_back(child);
}

void Group::Accept(Visitor* visitor)
{
	visitor->VisitGroup(this);
}

Node *Group::GetItem(unsigned int i)
{
	Node *temp = NULL;
	(i >= mList.size()) ? temp = NULL : temp = mList[i];
	return temp;
}


