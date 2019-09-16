#include "Interpretator.h"

Interpretator::Interpretator(void):filename("input.txt"),fin(filename)
{
  cout << "Object of class - Interpretator" << endl << "Magic method - constructor without parameters" << endl;
  if(!fin)
    throw MyException("File not available!!!");
}

Interpretator::Interpretator(const Interpretator& myInterpretator)
{
  cout << "Object of class - Interpretator" << endl << "Magic method - constructor for copy" << endl;
  filename = myInterpretator.filename;
}

Interpretator::Interpretator(string &myName):filename(myName),fin(filename)
{
  cout << "Object of class - Interpretator" << endl << "Magic method - constructor with parameters" << endl;
  if(!fin)
    throw MyException("File not available!!!");
}

Interpretator::~Interpretator(void)
{
  cout << "Object of class - Interpretator" << endl << "Magic method - destructor" << endl;
  
}

void Interpretator::operator =(Interpretator& myInterpretator)
{ 
  filename = myInterpretator.filename;
}

ostream &operator << (ostream &stream, Interpretator &myInterpretator)
{
  string line;
  while (getline(myInterpretator.fin, line))
  {
    string output = "";
    bool endline = false;
    for(char& c : line)
    {
      switch (c)
      {
        case '0':
          output += "zero ";
          break;
        case '1':
          output += "one ";
          break;
        case '2':
          output += "two ";
          break;
        case '3':
          output += "three ";
          break;
        case '4':
          output += "four ";
          break;
        case '5':
          output += "five ";
          break;
        case '6':
          output += "six ";
          break;
        case '7':
          output += "seven ";
          break;
        case '8':
          output += "eight ";
          break;
        case '9':
          output += "nine ";
          break;
        default:
          output+=c;
      }
      if(c == ' ' && endline)
      {
        stream << output << endl;
        output.clear();
      }
      endline = false;
      if(c == '.' || c==';' || c=='!' || c== '?')
        endline = true;
    }
    cout << output << endl;
  }
}