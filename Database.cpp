#include "Database.h"

Database::Database() {
	masterFaculty = new BST<Faculty>();
	masterStudent = new BST<Student>();
	choice = -1;
}

Database::~Database() {
	delete masterFaculty;
	delete masterStudent;
}

string Database::prompt(string msg) {
	string response = "";
	cout << msg;
	getline(cin, response);
	return response;
}
	

void Database::printAllStudents() {
	masterStudent->printAscendingTree(masterStudent->root);
}

void Database::printAllFaculty() {
	masterFaculty->printAscendingTree(masterFaculty->root);
}

void Database::printStudentByID() {
	int id;
	Student stud = masterStudent->searchByKey(id);
	cout << stud << endl;
}

void Database::printFacultyByID() {
	int id;
	Faculty fac = masterFaculty->searchByKey(id);
	cout << fac << endl;
}

void Database::printAdvisorByID() {
	int id;
	Student stud = masterStudent->searchByKey(id);
	Faculty advisor = masterFaculty->searchByKey(stud.getAdvisorID());
	cout << advisor << endl;
}

void Database::printAdviseesByID() {
	int id;
	Faculty fac = masterFaculty->searchByKey(id);
	for(int i = 0; i < fac.getAdvIDs()->getSize(); ++i){
		Student stud = masterStudent->searchByKey(id);
		cout << stud << endl;
	}
}

void Database::addStudent() {
	Student newStud = Student();
	
	newStud.setID(stoi(prompt("ID: ")));
	newStud.setName(prompt("Name: "));
	newStud.setYear(prompt("Year: "));
	newStud.setMajor(prompt("Major: "));
	newStud.setGPA(stod(prompt("GPA: ")));
	newStud.setAdvisorID(stoi(prompt("Advisor's ID: ")));
	
	masterStudent->insert(newStud);
}

void Database::remStudent() {
	masterStudent->deleteByKey(stoi(prompt("ID: ")));
}

void Database::addFaculty() {
	Faculty newFac = Faculty();
	
	newFac.setFacID(stoi(prompt("ID: ")));
	newFac.setName(prompt("Name: "));
	newFac.setLevel(prompt("Level: "));
	newFac.setDept(prompt("Department: "));
	DLL<int> *newAdvIDs = new DLL<int>;
	cout << "Enter the IDs of any advisees. Enter one period on its own line when finished." << endl;
	string input = "";
	while(true){
		getline(cin, input);
		if(input == "."){
			break;
		}
		newAdvIDs->insertBack(stoi(input));
	}
	newFac.setAdvIDs(newAdvIDs);
	masterFaculty->insert(newFac);	
}

void Database::remFaculty() {
	int id;
	masterFaculty->deleteByKey(id);
}

void Database::setNewAdvisor() {
	
}

void Database::remAdvisee() {
	
}

void Database::rollback() {
	
}

void Database::exit() {
	
}

void Database::mainLoop() {
	
}

void Database::writeToDisk() {
	
}

/*
void Database::() {
	
}


*/