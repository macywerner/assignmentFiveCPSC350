// Logan Welsh
// Student ID: 2325215
// Macy Werner
// Student ID: 2327782
// Assignment 5 CPSC350

#include "searchTree.cpp"
#include "student.h"
#include "faculty.h"
#include "Database.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv){
  
  //check for existing tables and deserialize if so
  /*
  ifstream inFSOne;
  BST<Faculty>* masterFaculty = new BST<Faculty>();

  inFSOne.open("facultyTable.txt");

  if(!inFSOne.is_open()){
    cout << "Could not open file. Creating facultyTable.txt" << endl;
  }
  else{
    masterFaculty->deSerialize(inFSOne);
  }

  ifstream inFSTwo;
  BST<Student>* masterStudent = new BST<Student>();

  inFSTwo.open("studentTable.txt");

  if(!inFSTwo.is_open()){
    cout << "Could not open file. Creating studentTable.txt" << endl;
  }
  else{
    masterStudent->deSerialize(inFSTwo);
  }

  printMenu();
  input();
  
  delete masterFaculty;
  delete masterStudent;
  */
  
  Database *db = new Database();
  
  db->mainLoop();
  
  delete db;
  
  return 0;
}
