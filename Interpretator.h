#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MyException.h"

using namespace std;

class Interpretator
{
public:
  explicit Interpretator(void);
  Interpretator(const Interpretator&);
  Interpretator(string&);
  ~Interpretator(void);
  friend ostream &operator << (ostream &, Interpretator &);
  void operator = (Interpretator&);
private:
  string filename;
  ifstream fin;
};
