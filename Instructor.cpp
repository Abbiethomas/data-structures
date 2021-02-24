#include <iostream>
#include <string>
#include "Instructor.h"
#include "Student.h"
using namespace std;

Instructor::Instructor() {
  //empty constructor
}

//constructor sets all values
Instructor::Instructor(string username, string password, string name, int classSize) {
  fullName = name;
  user = username;
  pass = password;
  numStudents = classSize;
}

bool Instructor::login(string username, string password) {
  if ((username == user) && (password == pass)) {
    return true;
  } else {
    return false;
  }
}

string Instructor::getUser() {
  return user;
}

string Instructor::getInstructorName() {
  return fullName;
}

//int returned represents the placement of the student in the array
int Instructor::getStudent(string username, Student arr[100]) {
  int studentID = -1;
  for(int i = 0; i < numStudents; i++) {
    if(username == arr[i].getUser()) {
      studentID = i;
      break;
    }
  }
    return studentID;
}

//int returned represents the placement of the student in the array
int Instructor::getMinStudent(int gradeType, Student arr[100]) {
  int min = 0;
  if (gradeType == 1) {
    for(int i = 0; i < numStudents; i++) {
      if (arr[min].getProjectGrade() > arr[i].getProjectGrade()) {
	min = i;
      }
    }
  } else if (gradeType == 2) {
    for(int i = 0; i < numStudents; i++) {
      if (arr[min].getQuizGrade() > arr[i].getQuizGrade()) {
	min = i;
      }
    }
  } else if (gradeType == 3) {
    for(int i = 0; i < numStudents; i++) {
      if (arr[min].getMidtermGrade() > arr[i].getMidtermGrade()) {
	min = i;
      }
    }
  } else if (gradeType == 4) {
    for(int i = 0; i < numStudents; i++) {
      if (arr[min].getFinalGrade() > arr[i].getFinalGrade()) {
	min = i;
      }
    }
  } else {
    for(int i = 0; i < numStudents; i++) {
      if (arr[min].getOverallGrade() > arr[i].getOverallGrade()) {
	min = i;
      }
    }
  }
  return min;
} //getMin

//int returned represents the placement of the student in the array
int Instructor::getMaxStudent(int gradeType, Student arr[100]) {
  int max = 0;
  if (gradeType == 1) {
    for(int i = 0; i < numStudents; i++) {
      if (arr[max].getProjectGrade() < arr[i].getProjectGrade()) {
	max = i;
      }
    }
  } else if (gradeType == 2) {
    for(int i = 0; i < numStudents; i++) {
      if (arr[max].getQuizGrade() < arr[i].getQuizGrade()) {
	max = i;
      }
    }
  } else if (gradeType == 3) {
    for(int i = 0; i < numStudents; i++) {
      if (arr[max].getMidtermGrade() < arr[i].getMidtermGrade()) {
	max = i;
      }
    }
  } else if (gradeType == 4) {
    for(int i = 0; i < numStudents; i++) {
      if (arr[max].getFinalGrade() < arr[i].getFinalGrade()) {
	max = i;
      }
    }
  } else {
    for(int i = 0; i < numStudents; i++) {
      if (arr[max].getOverallGrade() < arr[i].getOverallGrade()) {
	max = i;
      }
    }
  }
  return max;
} //getMaxStudent

double Instructor::getAvg(int gradeType, Student arr[100]) {
  double total = 0;
  if(gradeType == 1) {
    for(int i = 0; i < numStudents; i++) {
      total += arr[i].getProjectGrade();
    }
  } else if (gradeType == 2) {
    for(int i = 0; i < numStudents; i++) {
      total += arr[i].getQuizGrade();
    }
  } else if (gradeType == 3) {
    for(int i = 0; i < numStudents; i++) {
      total += arr[i].getMidtermGrade();
    }
  } else if (gradeType == 4) {
    for(int i = 0; i < numStudents; i++) {
      total += arr[i].getFinalGrade();
    }
  } else {
    for(int i = 0; i < numStudents; i++) {
      total += arr[i].getOverallGrade();
    }
  }
  return (total / numStudents);
} //getAvg

void Instructor::printStats(int gradeType, Student arr[100]) {
  cout << "Overall grade stats, " << endl;
  int minID = getMinStudent(gradeType, arr);
  int maxID = getMaxStudent(gradeType, arr);
  if(gradeType == 1) {
    cout << "\t min \t" << arr[minID].getProjectGrade() << "% (" <<
      arr[minID].getStudentName() << ")" << endl;
    cout << "\t max \t" << arr[maxID].getProjectGrade() << "% (" <<
      arr[maxID].getStudentName() << ")" << endl;
    cout << "\t avg \t" << getAvg(gradeType, arr) << "%" << endl;
  } else if(gradeType == 2) {
    cout << "\t min \t" << arr[minID].getQuizGrade() << "% (" <<
      arr[minID].getStudentName() << ")" << endl;
    cout << "\t max \t" << arr[maxID].getQuizGrade() << "% (" <<
      arr[maxID].getStudentName() << ")" << endl;
    cout << "\t avg \t" << getAvg(gradeType, arr) << "%" << endl;
  } else if(gradeType == 3) {
    cout << "\t min \t" << arr[minID].getMidtermGrade() << "% (" <<
      arr[minID].getStudentName() << ")" << endl;
    cout << "\t max \t" << arr[maxID].getMidtermGrade() << "% (" <<
      arr[maxID].getStudentName() << ")" << endl;
    cout << "\t avg \t" << getAvg(gradeType, arr) << "%" << endl;
  } else if(gradeType == 4) {
    cout << "\t min \t" << arr[minID].getFinalGrade() << "% (" <<
      arr[minID].getStudentName() << ")" << endl;
    cout << "\t max \t" << arr[maxID].getFinalGrade() << "% (" <<
      arr[maxID].getStudentName() << ")" << endl;
    cout << "\t avg \t" << getAvg(gradeType, arr) << "%" << endl;
  }  else {
    cout << "\t min \t" << arr[minID].getOverallGrade() << "% (" <<
      arr[minID].getStudentName() << ")" << endl;
    cout << "\t max \t" << arr[maxID].getOverallGrade() << "% (" <<
      arr[maxID].getStudentName() << ")" << endl;
    cout << "\t avg \t" << getAvg(gradeType, arr) << "%" << endl;
  }
}
