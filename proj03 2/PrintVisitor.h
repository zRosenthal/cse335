#ifndef PVISIT_H_
#define PVISIT_H_
class Employee;
class Group;
class Visitor {
    public:
        virtual void visitEmployee(Employee*)=0;
        virtual void visitGroup(Group*)=0;
        Visitor();
        virtual ~Visitor() {};
		Visitor(const Visitor &)=default;
		Visitor & operator=(const Visitor &)=default;
		virtual void Reset()=0;
};
class PrintVisitor:public Visitor {
    public:
        PrintVisitor();
        ~PrintVisitor()=default;
		PrintVisitor(const PrintVisitor&)=default;
		PrintVisitor& operator=(const PrintVisitor&)=default;
        void visitEmployee(Employee*);
        void visitGroup(Group*);
		void Reset() {};
	private:
		int indentLevel=0;
};

#endif
