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
		
		static const string STUD_FILE;
		static const string FAC_FILE;
		
		string prompt(string msg);
		int promptInt(string msg);
		bool checkInt(string response);
		void scoldBadInt();
		bool checkStudEmpty(string msg);
		bool checkFacEmpty(string msg);
		
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
	
	private:
		BST<Faculty> *masterFaculty;
		BST<Student> *masterStudent;
};