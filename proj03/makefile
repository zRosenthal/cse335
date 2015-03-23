proj03: main.o employee.o group.o pvisitor.o svisitor.o cvisitor.o
	g++ -std=c+11 main.o employee.o group.o pvisitor.o svisitor.o cvisitor.o -o proj03

main.o: main.cpp Employee.h Group.h PrintVisitor.h SearchVisitor.h CountVisitor.h
	g++ -std=c++11 -Wall -c main.cpp

employee.o: Employee.h Employee.cpp PrintVisitor.h
	g++ -std=c++11 -Wall -c Employee.cpp

group.o: Group.h Group.cpp PrintVisitor.h
	g++ -std=c++11 -Wall -c Group.cpp

pvisitor.o: PrintVisitor.h PrintVisitor.cpp Group.h Employee.h 
	g++ -std=c++11 -Wall -c PrintVisitor.cpp

svisitor.o: SearchVisitor.h SearchVisitor.cpp
	g++ -std=c++11 -Wall -c SearchVisitor.cpp
	
cvisitor.o: CountVisitor.h CountVisitor.cpp
	g++ -std=c++11 -Wall -c CountVisitor.cpp

clean:
	rm -f *o proj03
