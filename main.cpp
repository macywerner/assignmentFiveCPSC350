//#include "treeNode.cpp"
#include "searchTree.cpp"
#include "student.h"
#include "faculty.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv){

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
  return 0;
}
