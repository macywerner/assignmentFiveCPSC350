#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student{
public:
  Student();
  Student(int id, string name, string year, string major, double gpa, int advisorID);
  Student(const Student& other);
  ~Student();

  void operator=(const Student& s);
  
  bool operator==(const Student& s) const;
  bool operator!=(const Student& s) const;
  bool operator>(const Student& s) const;
  bool operator>=(const Student& s) const;
  bool operator<(const Student& s) const;
  bool operator<=(const Student& s) const;
  
  bool operator==(const int& id) const;
  bool operator!=(const int& id) const;
  bool operator>(const int& id) const;
  bool operator>=(const int& id) const;
  bool operator<(const int& id) const;
  bool operator<=(const int& id) const;
  
  friend ostream& operator<<(ostream& os, const Student& stud);

  void setID(int newID);
  void setName(string newName);
  void setYear(string newYear);
  void setMajor(string newMajor);
  void setGPA(double newGPA);
  void setAdvisorID(int newAdvisorID);

  int getID();
  string getName();
  string getYear();
  string getMajor();
  double getGPA();
  int getAdvisorID();
  
  string toString() const;

private:
  int id;
  string name;
  string year;
  string major;
  double gpa;
  int advisorID;

};

#endif