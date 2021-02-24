Student.o: Student.cpp Student.h
	g++ -Wall -g -std=c++1y -c Student.cpp	

Instructor.o: Instructor.cpp Instructor.h
	g++ -Wall -g -std=c++1y -c Instructor.cpp

main.o: main.cpp Instructor.h Student.h
	g++ -Wall -g -std=c++1y -c main.cpp

main: main.o Instructor.o Student.o
	g++ main.o Instructor.o Student.o -o main
