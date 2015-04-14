#include "Employee.h"
#include "Visitor.h"
using namespace std;

Employee::Employee(const string &fname, std::string lname="unknown", const string &position="unknown") : Node(fname), mLastName(lname), mPosition(position)
{
	// TODO Auto-generated constructor stub

}

Employee::~Employee()
{
	// TODO Auto-generated destructor stub
}

void Employee::Accept(Visitor* visitor)
{
	visitor->VisitEmployee(this);
}
