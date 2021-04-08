ItemType.o: ItemType.cpp ItemType.h
	g++ -Wall -pedantic -g -std=c++11 -c ItemType.cpp
DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h ItemType.h
	g++ -Wall -pedantic -g -std=c++11 -c DoublyLinkedList.cpp
main.o: main.cpp DoublyLinkedList.h ItemType.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp
main: main.o DoublyLinkedList.o ItemType.o 
	g++ main.o DoublyLinkedList.o ItemType.o -o main
