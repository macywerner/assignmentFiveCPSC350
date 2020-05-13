#include "student.h"
using namespace std;

Student::Student(){
  id = 0;
  name = "";
  year = "";
  major = "";
  gpa = 0.0;
  advisorID = 0;
}

Student::Student(int i_id, string i_name, string i_year, string  i_major, double i_gpa, int i_advisorID){
  id = i_id;
  name = i_name;
  year = i_year;
  major = i_major;
  gpa = i_gpa;
  advisorID = i_advisorID;
}

Student::Student(const Student& other){
  id = other.id;
  name = other.name;
  year = other.year;
  major = other.major;
  gpa = other.gpa;
  advisorID = other.advisorID;
}

Student::~Student(){
	
}

void Student::operator=(const Student& s){
  id = s.id;
  name = s.name;
  year = s.year;
  major = s.major;
  gpa = s.gpa;
  advisorID = s.advisorID;
}

bool Student::operator==(const Student& s) const{
  return this->id == s.id;
}
bool Student::operator!=(const Student& s) const{
  return this->id != s.id;
}
bool Student::operator>(const Student& s) const{
  return this->id > s.id;
}
bool Student::operator>=(const Student& s) const{
  return this->id >= s.id;
}
bool Student::operator<(const Student& s) const{
  return this->id < s.id;
}
bool Student::operator<=(const Student& s) const{
  return this->id <= s.id;
}

bool Student::operator==(const int& id) const{
  return this->id == id;
}
bool Student::operator!=(const int& id) const{
  return this->id != id;
}
bool Student::operator>(const int& id) const{
  return this->id > id;
}
bool Student::operator>=(const int& id) const{
  return this->id >= id;
}
bool Student::operator<(const int& id) const{
  return this->id < id;
}
bool Student::operator<=(const int& id) const{
  return this->id <= id;
}

ostream& operator<<(ostream& os, const Student& stud){
  os << stud.toString();
  return os;
}

string Student::toString() const{
  string outStr = "";
  outStr += to_string(id) + "\t";
  outStr += name + "\t";
  outStr += year + "\t";
  outStr += major + "\t";
  outStr += to_string(gpa) + "\t";
  outStr += to_string(advisorID);
  return outStr;
}


void Student::setID(int newID){
  id = newID;
}
void Student::setName(string newName){
  name = newName;
}
void Student::setYear(string newYear){
  year = newYear;
}
void Student::setMajor(string newMajor){
  major = newMajor;
}
void Student::setGPA(double newGPA){
  gpa = newGPA;
}
void Student::setAdvisorID(int newAdvisorID){
  advisorID = newAdvisorID;
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
