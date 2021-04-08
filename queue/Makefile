Queue.o: Queue.cpp Queue.h Customer.h
	g++ -Wall -pedantic -g -std=c++11 -c Queue.cpp
main.o: main.cpp Queue.h Customer.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp
main: main.o Queue.o
	g++ main.o Queue.o -o main
