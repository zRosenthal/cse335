proj04: main.o Employee.o Group.o PrintVisitor.o SearchVisitor.o CountVisitor.o Parser.o CompanyBuilder.o
	g++ -std=c++11 main.o Employee.o Group.o PrintVisitor.o SearchVisitor.o CountVisitor.o Parser.o CompanyBuilder.o -o proj04

main.o: main.cpp Employee.h Group.h PrintVisitor.h SearchVisitor.h CountVisitor.h CompanyBuilder.h Parser.h
	g++ -std=c++11 -w -c main.cpp

Employee.o: Employee.h Employee.cpp PrintVisitor.h
	g++ -std=c++11 -w -c Employee.cpp

Group.o: Group.h Group.cpp PrintVisitor.h
	g++ -std=c++11 -w -c Group.cpp

PrintVisitor.o: PrintVisitor.h PrintVisitor.cpp Group.h Employee.h 
	g++ -std=c++11 -w -c PrintVisitor.cpp

SearchVisitor.o: SearchVisitor.h SearchVisitor.cpp PrintVisitor.h
	g++ -std=c++11 -w -c SearchVisitor.cpp
	
CountVisitor.o: CountVisitor.h CountVisitor.cpp
	g++ -std=c++11 -w -c CountVisitor.cpp

CompanyBuilder.o: CompanyBuilder.h Group.h Employee.h SearchVisitor.h PrintVisitor.h
	g++ -std=c++11 -w -c CompanyBuilder.cpp

Parser.o: Parser.h CompanyBuilder.h
	g++ -std=c++11 -w -c Parser.cpp


clean:
	rm -f *o proj04
