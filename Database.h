#include "searchTree.cpp"
#include "student.h"
#include "faculty.h"
#include <fstream>
#include <string>

using namespace std;

class Database {
	
	public:
		Database();
		~Database();
		
		string prompt(string msg);
		
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
		void setNewAdvisor();
		void remAdvisee();
		void rollback();
		void exit();
		
		void mainLoop();
		void writeToDisk();
	
	private:
		BST<Faculty> *masterFaculty;
		BST<Student> *masterStudent;
		int choice;
};