#pragma once
#include <iostream>
#include "IteratorPtr.h"

using namespace std;
template <class T>
class IteratorPtr;

template <class T>
class Iterator
{
public:
	virtual void First(void) = 0;
	virtual void Next(void) = 0;
	virtual bool IsDone(void) const = 0;
	virtual T CurrentItem(void) const = 0;
protected:
	friend IteratorPtr<T>;
	virtual ~Iterator(void);
	Iterator(void);
};

template <class T>
Iterator<T>::Iterator(void)
{
	cout << "Object of class - Iterator" << endl << "Magic method - constructor without parameters" << endl;
}

template <class T>
Iterator<T>::~Iterator(void)
{
	cout << "Object of class - Iterator" << endl << "Magic method - destructor" << endl;
}