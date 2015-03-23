proj03: main.o Employee.o Group.o PrintVisitor.o SearchVisitor.o CountVisitor.o
	g++ -std=c++11 main.o Employee.o Group.o PrintVisitor.o SearchVisitor.o CountVisitor.o -o proj03

main.o: main.cpp Employee.h Group.h PrintVisitor.h SearchVisitor.h CountVisitor.h
	g++ -std=c++11 -Wall -c main.cpp

Employee.o: Employee.h Employee.cpp PrintVisitor.h
	g++ -std=c++11 -Wall -c Employee.cpp

Group.o: Group.h Group.cpp PrintVisitor.h
	g++ -std=c++11 -Wall -c Group.cpp

PrintVisitor.o: PrintVisitor.h PrintVisitor.cpp Group.h Employee.h 
	g++ -std=c++11 -Wall -c PrintVisitor.cpp

SearchVisitor.o: SearchVisitor.h SearchVisitor.cpp
	g++ -std=c++11 -Wall -c SearchVisitor.cpp
	
CountVisitor.o: CountVisitor.h CountVisitor.cpp
	g++ -std=c++11 -Wall -c CountVisitor.cpp

clean:
	rm -f *o proj03
