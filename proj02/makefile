proj01: main.o drink.o barista.o
	g++ -std=c++11 main.o drink.o barista.o -o proj01

main.o: main.cpp drink.h barista.h 
	g++ -std=c++11 -Wall -c main.cpp

drink.o: drink.cpp drink.h
	g++ -std=c++11 -Wall -c drink.cpp

barista.o: barista.cpp barista.h
	g++ -std=c++11 -Wall -c barista.cpp

clean: 
	rm -f *o proj02

