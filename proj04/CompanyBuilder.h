#ifndef CBUILDER_H_
#define CBUILDER_H_
class Group;
class Node;
class SearchVisitor;
class PrintVisitor;
#include<string>
using namespace std;
class Builder {
	public:
		Builder()=default;
		virtual ~Builder() {};
		virtual void printCompany()=0;
		virtual bool addEmp(string,string,string,string)=0;
		virtual	bool addGroup(string,string)=0;
		virtual	bool rmGroup(string)=0;
		virtual	bool disband(string)=0;
		virtual	Node* getResult()=0;
		virtual	void createCompany(string)=0;
};

class CompanyBuilder:public Builder {
	private:
		Group* root;
		SearchVisitor* sVisitor;
		PrintVisitor* pVisitor;	
	public:
		CompanyBuilder()=default;
		~CompanyBuilder();
		CompanyBuilder(const CompanyBuilder&)=default; 
		CompanyBuilder& operator=(const CompanyBuilder&)=default;
		void printCompany();
		bool addEmp(string,string,string,string);
		bool addGroup(string,string);
		bool rmGroup(string);
		bool disband(string);
		Node* getResult();
		void createCompany(string);
};


#endif
