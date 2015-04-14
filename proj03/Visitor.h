#ifndef VISITOR_H_
#define VISITOR_H_
#include "Group.h"
#include "Employee.h"
class Visitor
{
public:
	Visitor()=default;
        Visitor(const Visitor &v)=default;
        Visitor& operator=(const Visitor &rhs)=default;
	virtual ~Visitor();
	virtual void VisitGroup(Group *g ){};
	virtual void VisitEmployee(Employee *e){};
};

#endif /* VISITOR_H_ */
