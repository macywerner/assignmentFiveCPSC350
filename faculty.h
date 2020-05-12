#include <iostream>
#include "DLL.cpp"
using namespace std;

class Faculty{
public:
  Faculty();
  Faculty(int facID, string name, string level, string dept, DLL<int> *advIDs);
  Faculty(const Faculty& other);
  ~Faculty();

  void operator=(const Faculty& f);
  
  bool operator==(const Faculty& f);
  bool operator!=(const Faculty& f);
  bool operator>(const Faculty& f);
  bool operator>=(const Faculty& f);
  bool operator<(const Faculty& f);
  bool operator<=(const Faculty& f);
  
  bool operator==(const int& id);
  bool operator!=(const int& id);
  bool operator>(const int& id);
  bool operator>=(const int& id);
  bool operator<(const int& id);
  bool operator<=(const int& id);
  
  friend ostream& operator<<(ostream& os, const Faculty& stud);

  int setFacID();
  string setName();
  string setLevel();
  string setDept();
  DLL<int>* setIDs();
  
  int getFacID();
  string getName();
  string getLevel();
  string getDept();
  DLL<int>* getAdvIDs();

  string toString() const;

private:
  int facID;
  string name;
  string level;
  string dept;
  DLL<int> *advIDs;

  
};
