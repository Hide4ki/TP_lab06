#pragma once
#include <iostream>

using namespace std;

class MyException
{
private: 
	const char *message;
public:
	MyException(void);
	MyException(const char *);
	MyException(const MyException &);
	~MyException(void);
	friend ostream &operator << (ostream &stream,const MyException &);
};

