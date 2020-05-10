#include <iostream>
using namespace std;

class Faculty{
public:
  Faculty();
  Faculty(int id, string name, string level, string department);
  ~Faculty();

  int id;
  string name;
  string level;
  string department;
  //list ids;

  int getID();
  string getName();
  string getLevel();
  string getDepartment();
  //list getIDs();


};
