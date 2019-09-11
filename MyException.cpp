#include "MyException.h"

MyException::MyException(void)
{
	message = "Exception is undefined"; 
	cout << "Object of class - MyException" << endl << "Magic method - constructor without parameters" << endl;
}

MyException::MyException(const char *m):message(m)
{
	cout << "Object of class - MyException" << endl << "Magic method - constructor with parameters" << endl;
}

MyException::MyException(const MyException &myException)
{
	cout << "Object of class - MyException" << endl << "Magic method - constructor for copy" << endl;
	message = myException.message;
}

MyException::~MyException(void)
{
	cout << "Object of class - MyException" << endl << "Magic method - destructor" << endl;
}

ostream &operator << (ostream &stream,const MyException &myException)
{
	stream << myException.message << endl;
	return stream;
}
