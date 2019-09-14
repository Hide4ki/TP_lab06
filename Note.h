#pragma once
#include <iostream>
#include <string>

using namespace std;

class Note
{
public:
  Note(void);
  Note(const Note&);
  Note(string&);
  ~Note(void);
  bool operator == (const Note&) const;
  bool operator > (const Note&) const;
  void setName(string&);
  void setSurname(string&);
  void setNumber(string&);
  void setDate(int, int, int);
  string getName(void);  
  string getNumber(void);  
  string getSurname(void);  
  const int *getDate(void);
  friend ostream &operator << (ostream &, const Note &);
  friend istream &operator >> (istream &, Note &);
private:
  string name;
  string surname;
  string number;
  int dateBurn[3];
};

