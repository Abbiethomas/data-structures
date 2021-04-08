ItemType.o: ItemType.cpp ItemType.h
	g++ -Wall -pedantic -g -std=c++11 -c ItemType.cpp
Sorting.o: Sorting.h Sorting.cpp ItemType.h
	g++ -Wall -pedantic -g -std=c++11 -c Sorting.cpp
main.o: main.cpp Sorting.h ItemType.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp
main: main.o ItemType.o Sorting.o
	g++ main.o ItemType.o Sorting.o -o main
