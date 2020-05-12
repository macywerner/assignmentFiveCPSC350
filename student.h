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
  
  bool operator==(const Student& s);
  bool operator!=(const Student& s);
  bool operator>(const Student& s);
  bool operator>=(const Student& s);
  bool operator<(const Student& s);
  bool operator<=(const Student& id);
  
  bool operator==(const int& id);
  bool operator!=(const int& id);
  bool operator>(const int& id);
  bool operator>=(const int& id);
  bool operator<(const int& id);
  bool operator<=(const int& id);
  
  friend ostream& operator<<(ostream& os, const Student& stud);

  int setID();
  string setName();
  string setYear();
  string setMajor();
  double setGPA();
  int setAdvisorID();

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
