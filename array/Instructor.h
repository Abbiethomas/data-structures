#include <string>
#include "Student.h"

class Instructor {
public:
  Instructor();
  Instructor(std::string username, std::string password, std::string name, int classSize);
  bool login(std::string username, std::string password);
  std::string getUser();
  std::string getInstructorName();
  int getStudent(std::string username, Student arr[100]);
  int getMinStudent(int gradeType, Student arr[100]);
  int getMaxStudent(int gradeType, Student arr[100]);
  double getAvg(int gradeType, Student arr[100]);
  void printStats(int gradeType, Student arr[100]);

private:
  std::string fullName;
  std::string user;
  std::string pass;
  int numStudents;
};

