ItemType.o: ItemType.cpp ItemType.h
	g++ -Wall -pedantic -g -std=c++11 -c ItemType.cpp
CircularLinkedList.o: ItemType.h CircularLinkedList.h CircularLinkedList.cpp
	g++ -Wall -pedantic -g -std=c++11 -c CircularLinkedList.cpp
main.o: main.cpp ItemType.h CircularLinkedList.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp
main: main.o CircularLinkedList.o ItemType.o
	g++ main.o CircularLinkedList.o ItemType.o -o main
