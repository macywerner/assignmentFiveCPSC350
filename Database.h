// Logan Welsh
// Student ID: 2325215
// Macy Werner
// Student ID: 2327782
// Assignment 5 CPSC350

// Object for maintaining and manipulating two BSTs.

#include "searchTree.cpp"
#include "student.h"
#include "faculty.h"
#include <fstream>
#include <string>

using namespace std;

class Database {
	
	public:
		// Constructors
		Database();
		~Database();
		
		// Constants
		static const string STUD_FILE;	// Student table filename
		static const string FAC_FILE;	// Faculty table filename
		
		// Internal Functions
		string prompt(string msg);	// Show a message, get a response
		int promptInt(string msg);	// Same as above, but checks for proper integer
		bool checkInt(string response);	// Check if string can be converted to positive integer
		void scoldBadInt();	// Scold the user for inputting a bad integer
		bool checkStudEmpty(string msg);
		bool checkFacEmpty(string msg);
		
		// Menu-Displayed Functions
		void printAllStudents();
		void printAllFaculty();
		void printStudentByID();
		void printFacultyByID();
		void printAdvisorByID();
		void printAdviseesByID();
		void addStudent();
		void remStudent();
		void addFaculty();
		void remFaculty();
		void setNewAdvisor();	// !! Not yet implemented
		void remAdvisee();	// !! Not yet implemented
		void rollback();	// !! Not yet implemented
		void exit();
		
		void mainLoop();	// Shows menu, allows user to execute functions until they decide to leave
	
	private:
		BST<Faculty> *masterFaculty;	// Master faculty table
		BST<Student> *masterStudent;	// Master faculty table
};