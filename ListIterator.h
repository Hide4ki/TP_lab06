#pragma once
#include "MyException.h"
#include "List.h"
#include "Iterator.h"

template <class T>
class List;

template <class T>
class ListIterator:public Iterator<T>
{
public:
	ListIterator(const List<T>*);
	void First(void) override;
	void Next(void) override;
	bool IsDone(void) const override; 
	T CurrentItem(void) const override;
private:
	const List<T> *_list;
	long _current;
};

template <class T>
ListIterator<T>::ListIterator(const List<T> *aList):_list(aList),_current(0)
{
	cout << "Object of class - " << typeid(*this).name() << endl << "Magic method - constructor with parameters" << endl;
}

template <class T>
void ListIterator<T>::First(void)
{
	_current = 0;
}

template <class T>
void ListIterator<T>::Next(void)
{
	_current++;
}

template <class T>
bool ListIterator<T>::IsDone(void) const
{
	return _current >= _list->Count();
}

template <class T>
T ListIterator<T>::CurrentItem() const
{
	if(IsDone())
		throw MyException("IteratorOutBounds");
	return _list->Get(_current);
}
