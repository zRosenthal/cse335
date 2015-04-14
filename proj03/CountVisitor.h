#ifndef COUNT_VISITOR_H_
#define COUNT_VISITOR_H_

#include "Visitor.h"

class CountVisitor: public Visitor
{
public:
	CountVisitor()=default;
	virtual ~CountVisitor();
        CountVisitor(const CountVisitor &v)=default;
        CountVisitor& operator=(const CountVisitor &rhs)=default;
	virtual void VisitGroup(Group* g);
	virtual void VisitEmployee(Employee* e);
	void Reset(){mGroupCount = 0; mEmployeeCount=0;}
        void PrintResults(){std::cout <<"Number of Groups: " << mGroupCount << std::endl << "Number of Employees: " << mEmployeeCount << std::endl;};
private:
	int mGroupCount=0;
        int mEmployeeCount=0;
};

#endif /* COUNT_VISITOR_H_ */
