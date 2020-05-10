#include "student.h"
using namespace std;

Student::Student(){

}

Student::Student(int i_id, string i_name, string i_year, string  i_major, double i_gpa, int i_advisorID){
  id = i_id;
  name = i_name;
  year = i_year;
  major = i_major;
  gpa = i_gpa;
  advisorID = i_advisorID;
}

int Student::getID(){
  return id;
}

string Student::getName(){
  return name;
}

string Student::getYear(){
  return year;
}

string Student::getMajor(){
  return major;
}

double Student::getGPA(){
  return gpa;
}

int Student::getAdvisorID(){
  return advisorID;
}
