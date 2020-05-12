//#include "treeNode.cpp"
#include "searchTree.cpp"
#include "student.h"
#include "faculty.h"
#include <fstream>

using namespace std;

void One(){	// Print all students and their information
  //masterStudent->printAscendingTree();
  //print information
}

void Two(){	// Print all faculty and their information
  //masterFaculty->printAscendingTree();
  //print information
}

void Three(){	// Find and display student information given the students id
  int id = 0;
  cout << "Enter student ID: ";
  cin >> id;
  /*if(masterStudent->searchNode(id) = true){
    Student* foundStudent = masterStudent->searchTreeNode(id);
    cout << "Name: " << foundStudent->getName() << endl;
    cout << "Year: " << foundStudent->getYear() << endl;
    cout << "Major: " << foundStudent->getMajor() << endl;
    cout << "GPA: " << foundStudent->getGPA() << endl;
    cout << "Advisor's ID: " << foundStudent->getAdvisorID() << endl;
  }*/
}

void Four(){	// Find and display faculty information given the faculty id
  int id = 0;
  cout << "Enter Faculty ID: ";
  cin >> id;
  /*if(masterFaculty->searchNode(id) = true){
    Faculty* foundFaculty = masterFaculty->searchTreeNode(id);
    cout << "Name: " << foundFaculty->getName() << endl;
    cout << "Job Title: " << foundFaculty->getLevel() << endl;
    cout << "Department: " << foundFaculty->getDepartment() << endl;
    //add advisees
  }*/
}

void Five(){	// Given a student’s id, print the name and info of their faculty advisor
  int id = 0;
  cout << "Enter student ID: ";
  cin >> id;
  /*Student* foundStudent = masterStudent->searchTreeNode(id);
  int facultyID = foundStudent->getAdvisorID();
  Faculty* foundFaculty = masterFaculty->searchTreeNode(facultyID);
  cout << "Name: " << foundFaculty->getName() << endl;
  cout << "Job Title: " << foundFaculty->getLevel() << endl;
  cout << "Department: " << foundFaculty->getDepartment() << endl;
  //add advisees*/
}

void Six(){	// Given a faculty id, print ALL the names and info of his/her advisees.
  int id = 0;
  cout << "Enter faculty ID: ";
  cin >> id;
  //Faculty* foundFaculty = masterFaculty->searchTreeNode(id);
  //foundFaculty.getAdvisees();
  //for each loop
  /*cout << "Name: " << student.getName() << endl;
  cout << "Year: " << student.getYear() << endl;
  cout << "Major: " << student.getMajor() << endl;
  cout << "GPA: " << student.getGPA() << endl;*/
}

void Seven(){	// Add a new student
}

void Eight(){	// Delete a student given the id
  int answerID;
  cout << "Enter the ID of the student you would like to delete: " ;
  cin >> answerID;
  //masterStudent->deleteNode(answerID);
}

void Nine(){	// Add a new faculty member
}

void Ten(){	// Delete a faculty member given the id.
  int answerID;
  cout << "Enter the ID of the faculty you would like to delete: " ;
  cin >> answerID;
  //masterFaculty->deleteNode(answerID);
  //figure out how to make sure students are switched
}

void Eleven(){	// Change a student’s advisor given the student id and the new faculty id.

}
void Twelve(){	// Remove an advisee from a faculty member given the ids

}
void Thirteen(){	// Rollback

}
void Fourteen(){	// Exit

}


void printMenu(){
  cout << "1. Print all students and their information" << endl;
  cout << "2. Print all faculty and their information" << endl;
  cout << "3. Find and display student information given the student's id" << endl;
  cout << "4. Find and display faculty information given the faculty's id" << endl;
  cout << "5. Given a student's id, print the name and info of their faculty advisor" << endl;
  cout << "6. Given a faculty's id, print the names and info of his/her advisees" << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Add a new student" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member given the id" << endl;
  cout << "11. Change a student's advisor given the student id and the new faculty id" << endl;
  cout << "12. Remove an advisee from a faculty member given the ids" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
}


int input(){
  string answer;
  cout << "Enter the number of the action you wish: ";
  cin >> answer;
  int ansInt = stoi(answer);

  switch(ansInt){
    case 1:
      One();
      break;
    case 2:
      Two();
      break;
    case 3:
      Three();
      break;
    case 4:
      Four();
      break;
    case 5:
      Five();
      break;
    case 6:
      Six();
      break;
    case 7:
      Seven();
      break;
    case 8:
      Eight();
      break;
    case 9:
      Nine();
      break;
    case 10:
      Ten();
      break;
    case 11:
      Eleven();
      break;
    case 12:
      Twelve();
      break;
    case 13:
      Thirteen();
      break;
    case 14:
      Fourteen();
      break;
  }

}


int main(int argc, char** argv){

  /*
  ifstream inFSOne;
  //outstream outFSOne;
  //BST masterFaculty = new BST();

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
  //BST masterStudent = new BST();

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
  */
  
  
  BST<Student> *stud = new BST<Student>();
  
  //Student foo = Student(1, "Foo Bar", "2020", "Computer Science", 3.4, 666);
  
  Student studC = Student(15, "Leeroy Jenkins", "2020", "Computer Science", 3.4, 666);
  stud->insert(Student(10, "Foo Bar", "2020", "Computer Science", 3.4, 666));
  stud->insert(Student(5, "Bart Simpson", "2020", "Computer Science", 3.4, 666));
  stud->insert(studC);
 
  stud->printTree();
  
  //cout << '[' << stud->searchByKey(15) << ']' << endl;
  stud->deleteByKey(15);
  
  cout << endl;
  stud->printTree();

  delete stud;
  
  return 0;
}
