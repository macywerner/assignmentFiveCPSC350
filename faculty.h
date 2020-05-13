// Logan Welsh
// Student ID: 2325215
// Macy Werner
// Student ID: 2327782
// Assignment 5 CPSC350

#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
#include "DLL.cpp"
using namespace std;

class Faculty{
public:
  Faculty();
  Faculty(int facID, string name, string level, string dept, DLL<int> *advIDs);
  Faculty(const Faculty& other);
  ~Faculty();

  void operator=(const Faculty& f);
  
  bool operator==(const Faculty& f) const;
  bool operator!=(const Faculty& f) const;
  bool operator>(const Faculty& f) const;
  bool operator>=(const Faculty& f) const;
  bool operator<(const Faculty& f) const;
  bool operator<=(const Faculty& f) const;
  
  bool operator==(const int& id) const;
  bool operator!=(const int& id) const;
  bool operator>(const int& id) const;
  bool operator>=(const int& id) const;
  bool operator<(const int& id) const;
  bool operator<=(const int& id) const;
  
  friend ostream& operator<<(ostream& os, const Faculty& stud);

  void setFacID(int newFacID);
  void setName(string newName);
  void setLevel(string newLevel);
  void setDept(string newDept);
  void setAdvIDs(DLL<int>* newAdvIDs);
  
  int getFacID();
  string getName();
  string getLevel();
  string getDept();
  DLL<int>* getAdvIDs();

  string toString() const;

private:
  int facID;
  string name;
  string level;
  string dept;
  DLL<int> *advIDs;

  
};

#endif