#pragma once

#include "Iterator.h"

template <class T>
class Iterator;

template <class T>
class IteratorPtr
{
public:
	IteratorPtr(Iterator<T>*i);
	~IteratorPtr(void);
	Iterator<T>* operator->(void);
	Iterator<T>& operator*(void);
private:
  IteratorPtr(const IteratorPtr&) = delete;
	IteratorPtr& operator=(const IteratorPtr&) = delete;
	Iterator<T>* _i;
};

template<class T>
IteratorPtr<T>::IteratorPtr(Iterator<T>*i): _i(i)
{
	cout << "Object of class - IteratorPtr" << endl << "Magic method - constructor with parameters" << endl;
}

template<class T>
IteratorPtr<T>::~IteratorPtr(void)
{
	cout << "Object of class - IteratorPtr" << endl << "Magic method - destructor" << endl;
	delete _i;
}

template<class T>
Iterator<T> *IteratorPtr<T>::operator->(void)
{
	return _i;
}

template<class T>
Iterator<T> &IteratorPtr<T>::operator*(void)
{
	return *_i;
}