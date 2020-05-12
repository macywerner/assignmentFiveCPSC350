#include "faculty.h"
using namespace std;

Faculty::Faculty(){
  facID = 0;
  name = "";
  level = "";
  dept = "";
  advIDs = new DLL<int>();
}

Faculty::Faculty(int facID, string name, string level, string dept, DLL<int> *advIDs){
  this->facID = facID;
  this->name = name;
  this->level = level;
  this->dept = dept;
  this->advIDs = new DLL<int>(*advIDs);
}

Faculty::Faculty(const Faculty& other){
  facID = other.facID;
  name = other.name;
  level = other.level;
  dept = other.dept;
  advIDs = new DLL<int>(*other.advIDs);
}

Faculty::~Faculty(){
	delete advIDs;
}

void Faculty::operator=(const Faculty& f){
  facID = f.facID;
  name = f.name;
  level = f.level;
  dept = f.dept;
  advIDs = new DLL<int>(*f.advIDs);
}

bool Faculty::operator==(const Faculty& f) const{
  return this->facID == f.facID;
}
bool Faculty::operator!=(const Faculty& f) const{
  return this->facID != f.facID;
}
bool Faculty::operator>(const Faculty& f) const{
  return this->facID > f.facID;
}
bool Faculty::operator>=(const Faculty& f) const{
  return this->facID >= f.facID;
}
bool Faculty::operator<(const Faculty& f) const{
  return this->facID < f.facID;
}
bool Faculty::operator<=(const Faculty& f) const{
  return this->facID <= f.facID;
}

bool Faculty::operator==(const int& id) const{
  return this->facID == id;
}
bool Faculty::operator!=(const int& id) const{
  return this->facID != id;
}
bool Faculty::operator>(const int& id) const{
  return this->facID > id;
}
bool Faculty::operator>=(const int& id) const{
  return this->facID >= id;
}
bool Faculty::operator<(const int& id) const{
  return this->facID < id;
}
bool Faculty::operator<=(const int& id) const{
  return this->facID <= id;
}

ostream& operator<<(ostream& os, const Faculty& stud){
  os << stud.toString();
  return os;
}

string Faculty::toString() const{
  string outStr = "";
  outStr += to_string(facID) + "\t";
  outStr += name + "\t";
  outStr += level + "\t";
  outStr += dept + "\t";
  outStr += to_string(advIDs->getSize()) + "Advisees";
  return outStr;
}

void Faculty::setFacID(int newFacID){
  facID = newFacID;
}

void Faculty::setName(string newName){
  name = newName;
}

void Faculty::setLevel(string newLevel){
  level = newLevel;
}

void Faculty::setDept(string newDept){
  dept = newDept;
}

void Faculty::setAdvIDs(DLL<int>* newIDs){
  advIDs = new DLL<int>(*newIDs);
}


int Faculty::getFacID(){
  return facID;
}

string Faculty::getName(){
  return name;
}

string Faculty::getLevel(){
  return level;
}

string Faculty::getDept(){
  return dept;
}

DLL<int>* Faculty::getAdvIDs(){
  return new DLL<int>(*advIDs);
}