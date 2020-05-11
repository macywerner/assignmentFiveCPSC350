#include "faculty.h"
using namespace std;

Faculty::Faculty(){
  id = 0;
  name = "";
  level = "";
  department = "";
}

Faculty::Faculty(int i_id, string i_name, string i_level, string  i_department){
  id = i_id;
  name = i_name;
  level = i_level;
  department = i_department;
  //ids = i_IDs;
}

int Faculty::getID(){
  return id;
}

string Faculty::getName(){
  return name;
}

string Faculty::getLevel(){
  return level;
}

string Faculty::getDepartment(){
  return department;
}

/*Faculty::getIDs(){
  return ids;
}*/
