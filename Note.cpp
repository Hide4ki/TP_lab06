#include "Note.h"
#include <limits>

Note::Note(void)
{
  cout << "Object of class - Note" << endl << "Magic method - constructor without parameters" << endl;
  name = "";
  surname = "";
  number = "";
  dateBurn[0] = 0;
  dateBurn[1] = 0;
  dateBurn[2] = 0;
}     

Note::Note(string&mySurname)
{
  cout << "Object of class - Note" << endl << "Magic method - constructor with parameters" << endl;
  name = "";
  surname = mySurname;
  number = "";
  dateBurn[0] = 0;
  dateBurn[1] = 0;
  dateBurn[2] = 0;
}

Note::Note(const Note& myNote)
{
  cout << "Object of class - Note" << endl << "Magic method - constructor for copy" << endl;
  name        = myNote.name       ;
  surname     = myNote.surname    ;
  number      = myNote.number     ;
  dateBurn[0] = myNote.dateBurn[0];
  dateBurn[1] = myNote.dateBurn[1];
  dateBurn[2] = myNote.dateBurn[2];
}

Note::~Note(void)
{
  cout << "Object of class - Note" << endl << "Magic method - destructor" << endl;
}

bool Note::operator == (const Note &myNote) const
{
  return (surname == myNote.surname);
}

bool Note::operator > (const Note &myNote) const
{
  return (stoi(number.substr(0,2)) > stoi(myNote.number.substr(0,2)));
}

void Note::setName(string &myName)
{
  name = myName;
}

void Note::setSurname(string &mySurname)
{
  surname = mySurname;
}

void Note::setNumber(string &myNumber)
{
  number = myNumber;
}

void Note::setDate(int myDay, int myMonth, int myYear)
{
  dateBurn[0] = myDay;
  dateBurn[1] = myMonth;
  dateBurn[2] = myYear;
}

string Note::getName(void)
{
  return name;
} 

string Note::getSurname(void)
{
  return surname;
} 

string Note::getNumber(void)
{
  return number;
} 

const int *Note::getDate(void)
{
  return dateBurn;
}

ostream &operator << (ostream &stream, const Note &myNote)
{
  stream << "Name:" << myNote.name        << endl;
  stream << "Surname:" << myNote.surname  << endl;
  stream << "Number:" << myNote.number    << endl;
  stream << "Day:"  << myNote.dateBurn[0] << endl;
  stream << "Month:"<< myNote.dateBurn[1] << endl;
  stream << "Year:" << myNote.dateBurn[2] << endl;
  return stream;
}

istream &operator >> (istream &stream, Note &myNote)
{
  cout << "Input Name:";
  stream >> myNote.name  ;
  cout << "Input Surname:";
  stream >> myNote.surname ;
  cout << "Input Number:";
  stream >> myNote.number  ;
  cout << "Input Day:";
  stream >> myNote.dateBurn[0];
  cout << "Input Month:";
  stream >> myNote.dateBurn[1];
  cout << "Input Year:";
  stream >> myNote.dateBurn[2];
  while (stream.fail())
  {
    stream.clear();
    stream.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Error!!! Input don't correct, repeat input!!" << endl;
    cout << "Input Name:";
    stream >> myNote.name  ;
    cout << "Input Surname:";
    stream >> myNote.surname ;
    cout << "Input Number:";
    stream >> myNote.number  ;
    cout << "Input Day:";
    stream >> myNote.dateBurn[0];
    cout << "Input Month:";
    stream >> myNote.dateBurn[1];
    cout << "Input Year:";
    stream >> myNote.dateBurn[2];
  } 
  return stream;
}
