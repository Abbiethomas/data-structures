ItemType.o: ItemType.cpp ItemType.h
	g++ -Wall -pedantic -g -std=c++11 -c ItemType.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h ItemType.h
	g++ -Wall -pedantic -g -std=c++11 -c BinaryTree.cpp
main.o: main.cpp ItemType.h BinaryTree.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp
main: main.o ItemType.o BinaryTree.o
	g++ main.o ItemType.o BinaryTree.o -o main
