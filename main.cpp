#include "searchTree.cpp"
#include "student.h"
#include "faculty.h"
#include "Database.h"
#include <fstream>

using namespace std;


int input(){
  string answer;
  cout << "Enter the number of the action you wish: ";
  cin >> answer;
  int ansInt = stoi(answer);

  switch(ansInt){
    case 1:
      //One();
      break;
    case 2:
      //Two();
      break;
    case 3:
      //Three();
      break;
    case 4:
      //Four();
      break;
    case 5:
      //Five();
      break;
    case 6:
      //Six();
      break;
    case 7:
      //Seven();
      break;
    case 8:
      //Eight();
      break;
    case 9:
      //Nine();
      break;
    case 10:
      //Ten();
      break;
    case 11:
      //Eleven();
      break;
    case 12:
      //Twelve();
      break;
    case 13:
      //Thirteen();
      break;
    case 14:
      //Fourteen();
      break;
  }

}


int main(int argc, char** argv){

  /*
  ifstream inFSOne;
  //outstream outFSOne;
  BST<Faculty> *masterFaculty = new BST<Faculty>();

  inFSOne.open("facultyTable.txt");

  int currentFacultyID = 0;

  if(!inFSOne.is_open()){
    cout << "Could not open file. Creating facultyTable.txt" << endl;
    //outFSOne.open("facultyTable.txt");
  }
  else{
    while(!inFSOne.eof()){
      inFSOne >> currentFacultyID;
      //read file into tree

    }
  }

  ifstream inFSTwo;
  //outstream outFSTwo;
  BST<Student> *masterStudent = new BST<Student>();

  inFSTwo.open("studentTable.txt");

  if(!inFSTwo.is_open()){
    cout << "Could not open file. Creating studentTable.txt" << endl;
    //outFSTwo.open("studentTable.txt");
  }
  else{
    while(!inFSTwo.eof()){
      inFSOne >> currentFacultyID;
      //read file into tree

    }
  }

  printMenu();
  input();
  
  delete masterFaculty;
  delete masterStudent;
  */
  
  Database *db = new Database();
  
  db->printAllStudents();

  db->addStudent();
  
  db->printAllStudents();
  
  db->remStudent();
  
  db->printAllStudents();

  delete db;
  
  return 0;
}
