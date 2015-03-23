proj01: main.o drink.o
	g++ -std=c++11 main.o drink.o -o proj01

main.o: main.cpp drink.h 
	g++ -std=c++11 -Wall -c main.cpp

drink.o: drink.cpp drink.h
	g++ -std=c++11 -Wall -c drink.cpp

clean: 
	rm -f *o proj01

