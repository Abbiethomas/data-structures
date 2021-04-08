#include <string.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include "Instructor.h"
#include "Student.h"
using namespace std;

/* studentView is a function that is called when the user indicates they would 
   like to log in as a student.
   Requests username and password
   Offers query options for students
 */
void studentView(Student sArr[100], int numS) {
  string user;
  string pass;
  cout << "Enter Credentials to login,\n\t Enter Username: ";
  cin >> user;
  cout << "\t Enter Password: ";
  cin >> pass;

  int studentID = -1;
  for(int i = 0; i < numS; i++) {
    if(sArr[i].login(user, pass)) {
      studentID = i;
      break;
    }
  } //iterating through student usernames

  if (studentID == -1) {
    cout << "Login as Student failed" << endl;
    return;
  } //login as student failed, return to main

  cout << "You are now logged in as " << sArr[studentID].getStudentName() << endl;

  cout << "Do you want to view grades (y/n)?";
  char grades;
  cin >> grades;
  if (grades == 'y') {
    cout << "Student name: " << sArr[studentID].getStudentName() << endl;
    cout << "\t Project \t" << sArr[studentID].getProjectGrade() << "%" << endl;
    cout << "\t Quiz \t\t" << sArr[studentID].getQuizGrade() << "%" << endl;
    cout << "\t Midterm \t" << sArr[studentID].getMidtermGrade() << "%" << endl;
    cout << "\t Final \t \t" << sArr[studentID].getFinalGrade() << "%" << endl;
    cout << "\t Overall \t" << sArr[studentID].getOverallGrade() << "%" << endl;
  }
    return;
} //student view


/* instructorView is a function that is called when the user indicates they would
   like to log in as an instructor.
   Requests username and password (returns if login fails)
   Offers query options for instructors
 */
void instructorView(Instructor iArr[10], Student sArr[100], int numI, int numS) {
  string user;
  string pass;
  cout << "Enter Credentials to login,\n\t Enter Username: ";
  cin >> user;
  cout << "\t Enter Password: ";
  cin >> pass;

  int instructorID = -1; //represents where user is in array
  for(int i = 0; i < numI; i++) {
    if(iArr[i].login(user, pass)) {
      instructorID = i;
      break;
    }
  } //iterating through instructor usernames

  if (instructorID == -1) {
    cout << "Login as Instructor failed" << endl;
    return;
  } //login as instructor failed, return to main

  cout << "You are now logged in as " << iArr[instructorID].getInstructorName() << endl;


  int opt = -1;
  while (opt == -1) { //while loop that gives instructors options
    cout << "Query options,\n\t 1 - view grades of a student\n\t 2 - view stats\n\t Enter option number: ";
    cin >> opt; //takes option from user

    if (opt == 1) { //OPTION 1 (grades of student)
      cout << "Enter student username to view grades: ";
      string sUser;
      cin >> sUser;
      int studentID = iArr[instructorID].getStudent(sUser, sArr); //get Student

      if (studentID == -1) {
	cout << "Student username not valid." << endl;
	opt = -1; //incorrect student username, return to query options
      } else {
	cout << "Student name: " << sArr[studentID].getStudentName() << endl;
	cout << "\t Project \t" << sArr[studentID].getProjectGrade() << "%" << endl;
	cout << "\t Quiz \t\t" << sArr[studentID].getQuizGrade() << "%" << endl;
	cout << "\t Midterm \t" << sArr[studentID].getMidtermGrade() << "%" << endl;
	cout << "\t Final \t\t" << sArr[studentID].getFinalGrade() << "%" << endl;
	cout << "\t Overall \t" << sArr[studentID].getOverallGrade() << "%" << endl;
      } //correct student username
    } else if (opt == 2) { //OPTION 2 (stats)
      int gradeType = -1;
      while (gradeType == -1) {
	cout << "Grade types,\n\t 1 - Project grade\n\t 2 - Quiz grade\n\t 3 - Midterm grade\n\t 4 - Final grade\n\t 5 - Overall grade\nSelect a grade type to view stats:";
	cin >> gradeType;
	if ((gradeType > 0) && (gradeType < 6)) {
	  iArr[instructorID].printStats(gradeType, sArr);
	} else {
	  cout << "Invalid option. Please enter a valid option." << endl;
	  gradeType = -1; //asks grade type again
	}
      } //while loop (grade type)
    } else { //OPTION INVALID
      cout << "Invalid option. Please enter a valid option" << endl;
      opt = -1;
    }
  } //options loop
} //instructor view


/* Main function first checks that the correct arguments are passed and fills 
   the student array and the instructor array.
   gives login options as instructor or student then calls appropriate function
   gives login option until '3' is entered
 */
int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Correct Usage: main [instructors_file] [students_file]" << endl;
    return 1;
  } else if (strcmp(argv[1], "instructors.txt") != 0) {
    cout << "Error: cannot parse intructors information from file " << argv[1] << endl;
    return 2;
  } else if (strcmp(argv[2], "students.txt") != 0) {
    cout << "Error: cannot parse student information from file " << argv[2] << endl;
    return 3;
  } else {
    cout << "Parsing instructors and students information success\n..." << endl;
  }//checking arguments passed

  ifstream instructors(argv[1], ifstream::in);
  ifstream students(argv[2], ifstream::in); //opening .txt files

  int numStudents = 0; 
  Student* studentArr = new Student[100];
  char n;
  while(students >> n) {
    students.unget();
    string user;
    string pass;
    string name;
    string grade;
    getline(students, user, '\t');
    getline(students, pass, '\t');
    getline(students, name, '\t');
    getline(students, grade, '\t');
    int pGrade = stoi(grade);
    getline(students, grade, '\t');
    int qGrade = stoi(grade);
    getline(students, grade, '\t');
    int mGrade = stoi(grade);
    getline(students, grade, '\n');
    int fGrade = stoi(grade);
    studentArr[numStudents] = Student(user, pass, name, pGrade, qGrade, mGrade, fGrade);
    numStudents++;
  } //filling student array


  Instructor* instructorArr = new Instructor[20];
  int numInstructors = 0;
  char m;
  while(instructors >> m) {
    instructors.unget();
    string user;
    string pass;
    string name;
    getline(instructors, user, '\t');
    getline(instructors, pass, '\t');
    getline(instructors, name, '\n');
    instructorArr[numInstructors] = Instructor(user, pass, name, numStudents);
    numInstructors++;
  } //filling instructor array

  int userType = 0;
  while(userType == 0) {
    cout << "User types, \n\t1 - Instructor\n\t2 - Student\nSelect a login user type or enter 3 to exit: ";
    cin >> userType;
    if (userType == 1) {
      instructorView(instructorArr, studentArr, numInstructors, numStudents);
      userType = 0; //allows while loop to continue
    } else if (userType == 2) {
      studentView(studentArr, numStudents);
      userType = 0; //allows while loop to continue
    } else if (userType == 3) {
      return 0; //EXIT_SUCCESS
    } else {
      cout << "Invalid option. Please enter a valid option." << endl;
      userType = 0; //allows while loop to continue
    }
  } //Selecting User Types

} //main
