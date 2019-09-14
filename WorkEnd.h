#pragma once 

#include <iostream>

using namespace std;

class WorkEnd
{
public:
	WorkEnd(void);
	WorkEnd(const int &);
	WorkEnd(const WorkEnd &);
	~WorkEnd(void);
	friend ostream &operator << (ostream &stream,const WorkEnd &);
private:
	int cnt;
};