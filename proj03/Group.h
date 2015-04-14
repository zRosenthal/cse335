#ifndef GROUP_H_
#define GROUP_H_

#include "Node.h"
#include <vector>
#include <string>

class Group: public Node
{
public:
	Group(const std::string &name);
	virtual ~Group();
        Group(const Group &v)=default;
        Group& operator=(const Group &rhs)=default;
	void AddChild(Node *child);
	virtual void Accept(Visitor* visitor);
	unsigned int GetSize()const{return mList.size();}
	Node* GetItem(unsigned int i);
	virtual void Print();
	virtual std::string GetFormatName(){return std::string("+ Team "+Node::GetName());}
private:
	std::vector<Node*>mList;

};

#endif /* GROUP_H_ */
