#ifndef PRINTVISITOR_H_
#define PRINTVISITOR_H_

#include "Visitor.h"

class PrintVisitor: public Visitor
{
public:
	PrintVisitor()=default;
	virtual ~PrintVisitor();
        PrintVisitor(const PrintVisitor &v)=default;
        PrintVisitor& operator=(const PrintVisitor &rhs)=default;
	virtual void VisitGroup(Group* g);
	virtual void VisitEmployee(Employee* e);
	void PrintIndent();
	void Reset(){mIndent = 0;}
private:
	int mIndent=0;
};

#endif /* PRINTVISITOR_H_ */
