#include <iostream>
using namespace std;

class Student{
public:
  Student();
  Student(int id, string name, string year, string major, double gpa, int advisorID);
  ~Student();

  int id;
  string name;
  string year;
  string major;
  double gpa;
  int advisorID;

  int getID();
  string getName();
  string getYear();
  string getMajor();
  double getGPA();
  int getAdvisorID();
  

};
