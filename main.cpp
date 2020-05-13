#include "searchTree.cpp"
#include "student.h"
#include "faculty.h"
#include "Database.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv){
  
  Database *db = new Database();
  
  db->mainLoop();
  
  delete db;
  
  return 0;
}
