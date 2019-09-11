#pragma once

#include "Iterator.h"

template <class T>
class IteratorPtr
{
public:
	IteratorPtr(Iterator<T>*i);
	~IteratorPtr(void);
	Iterator<T>* operator->(void);
	Iterator<T>& operator*(void);
private:
	IteratorPtr(const IteratorPtr&);
	IteratorPtr& operator=(const IteratorPtr&);
	Iterator<T>* _i;
};

template<class T>
IteratorPtr<T>::IteratorPtr(Iterator<T>*i): _i(i)
{
}

template<class T>
IteratorPtr<T>::~IteratorPtr(void)
{
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