#include <string>
#ifndef STUDENT_H
#define STUDENT_H

class Student {
public:  
  Student();
  Student(std::string username, std::string password, std::string name, int pG, int qG, int mG, int fG);
  bool login(std::string username, std::string password);
  std::string getUser();
  std::string getStudentName();
  int getProjectGrade();
  int getQuizGrade();
  int getMidtermGrade();
  int getFinalGrade();
  double getOverallGrade();

private:
  std::string fullName;
  std::string user;
  std::string pass;
  int projectGrade;
  int quizGrade;
  int midtermGrade;
  int finalGrade;
};

#endif
