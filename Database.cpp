#include "Database.h"

Database::Database() {
	masterFaculty = new BST<Faculty>();
	masterStudent = new BST<Student>();
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

int Database::promptInt(string msg) {
	string response = "";
	int num = 0;
	while(true){
		response = prompt(msg);
		if(checkInt(response)){
			num = stoi(response);
			break;
		}
		else{
			scoldBadInt();
		}
	}
	return num;
}

bool Database::checkInt(string response){
	if(response.size() == 0){
		return false;
	}
	for(int i = 0; i < response.size(); ++i){
		if(response[i] < '0' || response[i] > '9'){
			return false;
		}
	}
	return true;
}

void Database::scoldBadInt(){
	cout << "Please enter a valid number." << endl;
}

bool Database::checkStudEmpty(string msg){
	if(masterStudent->isEmpty()){
		cout << "There are currently no students in the database." << endl;
		return true;
	}
	else{
		cout << msg << endl << endl;
		return false;
	}
}

bool Database::checkFacEmpty(string msg){
	if(masterFaculty->isEmpty()){
		cout << "There are currently no faculty in the database." << endl;
		return true;
	}
	else{
		cout << msg << endl << endl;
		return false;
	}
}

void Database::printAllStudents() {
	if(!checkStudEmpty("Printing all students.")){
		masterStudent->printAscendingTree(masterStudent->root);
	}
}

void Database::printAllFaculty() {
	if(!checkFacEmpty("Printing all faculty.")){
		masterFaculty->printAscendingTree(masterFaculty->root);
	}
}

void Database::printStudentByID() {
	if(!checkStudEmpty("Printing student by ID.")){
		Student stud = masterStudent->searchByKey(promptInt("ID: "));
		cout << stud << endl;
	}
}

void Database::printFacultyByID() {
	if(!checkFacEmpty("Printing faculty by ID.")){
		Faculty fac = masterFaculty->searchByKey(promptInt("ID: "));
		cout << fac << endl;
	}
}

void Database::printAdvisorByID() {
	if(!checkStudEmpty("Printing student's advisor by student's ID.")){
		Student stud = masterStudent->searchByKey(promptInt("ID: "));
		Faculty advisor = masterFaculty->searchByKey(stud.getAdvisorID());
		cout << advisor << endl;
	}
}

void Database::printAdviseesByID() {
	if(!checkFacEmpty("Printing student's advisor by student's ID.")){
		Faculty fac = masterFaculty->searchByKey(promptInt("ID: "));
		for(int i = 0; i < fac.getAdvIDs()->getSize(); ++i){
			Student stud = masterStudent->searchByKey(fac.getAdvIDs()->peek(i));
			cout << stud << endl;
		}
	}
}

void Database::addStudent() {
	Student newStud = Student();
	
	newStud.setID(promptInt("ID: "));
	newStud.setName(prompt("Name: "));
	newStud.setYear(prompt("Year: "));
	newStud.setMajor(prompt("Major: "));
	newStud.setGPA(stod(prompt("GPA: ")));	// FIX: Check for proper double
	newStud.setAdvisorID(promptInt("Advisor's ID: "));
	
	masterStudent->insert(newStud);
}

void Database::remStudent() {
	masterStudent->deleteByKey(promptInt("ID: "));
}

void Database::addFaculty() {
	Faculty newFac = Faculty();
	
	newFac.setFacID(promptInt("ID: "));
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
		else if(input != ""){
			if(checkInt(input)){
				newAdvIDs->insertBack(stoi(input));
			}
			else{
				scoldBadInt();
			}
		}
	}
	newFac.setAdvIDs(newAdvIDs);
	masterFaculty->insert(newFac);	
}

void Database::remFaculty() {
	masterFaculty->deleteByKey(promptInt("ID: "));
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
	int choice = 0;
	while(true){
		cout << endl;
		cout << "Choose one of the following:" << endl;
		cout << "1.\tPrint all students and their information (sorted by ascending id #)" << endl;
		cout << "2.\tPrint all faculty and their information (sorted by ascending id #)" << endl;
		cout << "3.\tFind and display student information given the students id" << endl;
		cout << "4.\tFind and display faculty information given the faculty id" << endl;
		cout << "5.\tGiven a student’s id, print the name and info of their faculty advisor" << endl;
		cout << "6.\tGiven a faculty id, print ALL the names and info of his/her advisees." << endl;
		cout << "7.\tAdd a new student" << endl;
		cout << "8.\tDelete a student given the id" << endl;
		cout << "9.\tAdd a new faculty member" << endl;
		cout << "10.\tDelete a faculty member given the id." << endl;
		cout << "11.\tChange a student’s advisor given the student id and the new faculty id." << endl;
		cout << "12.\tRemove an advisee from a faculty member given the ids" << endl;
		cout << "13.\tRollback" << endl;
		cout << "14.\tExit" << endl;
		cout << endl;
		
		while(true){
			choice = promptInt("> ");
			if(choice < 1 || choice > 14){
				scoldBadInt();
			}
			else{
				break;
			}
		}
		
		cout << endl;
		
		switch(choice){
			case 1:
				printAllStudents();
				break;
			case 2:
				printAllFaculty();
				break;
			case 3:
				printStudentByID();
				break;
			case 4:
				printFacultyByID();
				break;
			case 5:
				printAdvisorByID();
				break;
			case 6:
				printAdviseesByID();
				break;
			case 7:
				addStudent();
				break;
			case 8:
				remStudent();
				break;
			case 9:
				addFaculty();
				break;
			case 10:
				remFaculty();
				break;
			case 11:
				setNewAdvisor();
				break;
			case 12:
				remAdvisee();
				break;
			case 13:
				rollback();
				break;
			case 14:
				exit();
				break;
			default:
				//scoldBadInt();
				break;
		}
		
		if(choice >= 1 && choice <= 13){
			cout << endl;
			prompt("Press Enter to return to the main menu.");
		}
		else if(choice == 14){
			break;
		}
	}
}

void Database::writeToDisk() {
	
}

/*
void Database::() {
	
}


*/