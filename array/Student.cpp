#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
using namespace std;

Student::Student() {
  //empty constructor
}

//constructor initializes all values
Student::Student(string username, string password, string name, int pG, int qG, int mG, int fG) {
  user = username;
  pass = password;
  fullName = name;
  projectGrade = pG;
  quizGrade = qG;
  midtermGrade = mG;
  finalGrade = fG;
}

bool Student::login(string username, string password) {
  if ((username == user) && (password == pass)) {
    return true;
  } else {
    return false;
  }
}

string Student::getUser() {
  return user;
}

string Student::getStudentName() {
  return fullName;
}

int Student::getProjectGrade() {
  return projectGrade;
}

int Student::getQuizGrade() {
  return quizGrade;
}

int Student::getMidtermGrade() {
  return midtermGrade;
}

int Student::getFinalGrade() {
  return finalGrade;
}

double Student::getOverallGrade() {
  double overallGrade = 0;
  overallGrade += (projectGrade * 0.3);
  overallGrade += (quizGrade * 0.1);
  overallGrade += (midtermGrade * 0.2);
  overallGrade += (finalGrade * 0.4);
  return overallGrade;
}
