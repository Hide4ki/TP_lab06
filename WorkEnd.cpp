#include "WorkEnd.h"

WorkEnd::WorkEnd(void)
{
	cout << "Object of class - WorkEnd" << endl << "Magic method - constructor without parameters" << endl;
	cnt = 0;
}

WorkEnd::WorkEnd(const int &cntCommand)
{
	cout << "Object of class - WorkEnd" << endl << "Magic method - constructor with parameters" << endl;
	cnt = cntCommand;
}

WorkEnd::WorkEnd(const WorkEnd& myEnd)
{
	cout << "Object of class - WorkEnd" << endl << "Magic method - constructor for copy" << endl;
	cnt = myEnd.cnt;
}

WorkEnd::~WorkEnd(void)
{
	cout << "Object of class - WorkEnd" << endl << "Magic method - destructor" << endl;
}

ostream &operator << (ostream &stream,const WorkEnd &myEnd)
{
	return stream;
}