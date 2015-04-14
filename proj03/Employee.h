#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Node.h"
#include <iostream>
#include <string>
class Employee: public Node
{
public:
	Employee(const std::string &fname, std::string lname, const std::string& position);
	virtual ~Employee();
        Employee(const Employee &v)=default;
        Employee& operator=(const Employee &rhs)=default;
	void SetExtension(std::string &ext){mPosition = ext;}
	virtual void Accept(Visitor* visitor);
	std::string GetPosition() const {return mPosition;}
        std::string GetLastName() const {return mLastName;}
	virtual void Print(){std::cout<<GetPosition()<<": "<<GetName()<< " " << mLastName<<std::endl;}
	virtual std::string GetFormatName(){return GetPosition()+": "+GetName()+ " " + mLastName;}
    private:
	std::string mPosition;
        std::string mLastName;
};

#endif /* EMPLOYEE_H_ */
