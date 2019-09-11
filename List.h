#pragma once
#include <iostream>
#include "ListIterator.h"
#include "Item.h"
#define DEFUALT_LIST_CAPACITY 10
template <class T>
class ListIterator;

template <class T>
class List
{
	class Elem;
public:
	List(long size = DEFUALT_LIST_CAPACITY);
	List(const List<T>&);
	~List(void);
	
	List<T>& operator=(const List<T>&);
	
	long Count(void) const;
	T& Get(long index) const;
	T& First(void) const;
	T& Last(void) const;
	bool Includes(const T&);

	void Append(const T&);
	void Prepend(const T&);

	void Remove(const T&);
	void RemoveLast(void);
	void RemoveFirst(void);
	void RemoveAll(void);

	T& Top(void) const;
	void Push(const T&);
	T& Pop(void);

	ListIterator<T> *GetCorrectIterator(void);

private: 
	void Init(void);
	void GetCashe(void) const;
	void SetCashe(void);
	void CheckCashe(void);
	bool CheckIndex(long) const;
	Elem *SearchElem(const T&);
	bool Empty(void) const;
	Elem *_first;
	Elem *_last;
	long _size;
	T **_cashe;
	long _casheSize;
	bool *_cashcorrect;
};

template <class T>
class List<T>::Elem
{
	Elem *next;
	Elem *prev;
	T *item;
	void makeFictitious(void);
	bool fictitious(void);
	Elem(void);
	~Elem(void);
	friend List;
};

template <class T>
void List<T>::Elem::makeFictitious(void)
{
	delete item;
	item = 0;
}

template <class T>
bool List<T>::Elem::fictitious(void)
{
	return !item;
}

template <class T>
List<T>::Elem::Elem(void):next(0),prev(0),item(0)
{
}

template <class T>
List<T>::Elem::~Elem(void)
{
	delete item;
}

template <class T>
List<T>::List(const List<T> &myList)
{
	Init();

	ListIterator<T> i(&myList);

	for(i.First();!i.IsDone();i.Next())
		Append(i.CurrentItem());
}

template <class T>
List<T>::List(long size)
{
	Init();

	Elem *temp = _first = _last = new Elem;
	for(int i = 1; i<size; i++)
	{
		Elem *now = new Elem;
		temp->next = now;
		now->prev = temp;
		temp = now;
	}
	_first->prev = temp;
	temp->next = _first;
}

template <class T>
List<T>::~List(void)
{
	Elem *i = _first;
	_first->prev->next = 0;
	while(i->next)
	{
		Elem *prev = i;
		i = i->next;
		delete prev;
	}

	delete i;
	delete[] _cashe;
	delete _cashcorrect;
}

template <class T>
List<T> &List<T>::operator=(const List<T> &myList)
{
	RemoveAll();

	ListIterator<T> i(&myList);

	for(i.First();!i.IsDone();i.Next())
		Append(i.CurrentItem());
	return *this;
}

template <class T>
long List<T>::Count(void) const
{
	return _size;
}

template <class T>
T &List<T>::Get(long index) const
{
	if(!CheckIndex(index))
		throw MyException("ReqevestOutBounds");
	if(!*_cashcorrect)
		GetCashe();
	return *_cashe[index];
}

template <class T>
T &List<T>::First(void)const
{
	if(!_first->item)
		throw MyException("List is empty!!");
	return *_first->item;
}

template <class T>
T &List<T>::Last(void) const
{
	if(!_last->item)
		throw MyException("List is empty!!");
	return *_last->item;
}

template <class T>
bool List<T>::Includes(const T &searchItem)
{
	ListIterator<T> i(this);
	
	for(i.First();!i.IsDone();i.Next())
		if(i.CurrentItem() == searchItem)
			return true;
	return false;
}

template <class T>
void List<T>::Append(const T &newItem)
{
	if(!_last)
	{
		_last = _first = new Elem;
		_last->prev = _last;
		_last->next = _last;
		_last->item = new T;
		*_last->item = newItem;
	}
	else if(!_last->item)
	{
		_last->item = new T;
		*_last->item = newItem;
	}
	else if(_last->next->fictitious())
	{
		_last = _last->next;
		_last->item = new T;
		*_last->item = newItem;
	}
	else
	{
		Elem *temp = _last;
		_last = new Elem;
		temp->next = _last;
		_last->prev = temp;
		_last->next = _first;
		_first->prev = _last;
		_last->item = new T;
		*_last->item = newItem;
	}

	_size++;
	CheckCashe();
	*_cashcorrect = false;
}

template <class T>
void List<T>::Prepend(const T &newItem)
{
	if(!_first)
	{
		_first = _last = new Elem;
		_first->next = _first;
		_first->prev = _first;
		_first->item = new T;
		*_first->item = newItem;
	}
	else if(!_first->item)
	{
		_first->item = new T;
		*_first->item = newItem;
	}
	else if(_first->prev->fictitious())
	{
		_first = _first->prev;
		_first->item = new T;
		*_first->item = newItem;
	}
	else
	{
		Elem *temp = _first;
		_first = new Elem;
		temp->prev = _first;
		_first->next = temp;
		_last->next = _first;
		_first->prev = _last;
		_first->item = new T;
		*_first->item = newItem;
	}

	_size++;
	CheckCashe();
	*_cashcorrect = false;
}

template <class T>
void List<T>::Remove(const T &dItem)
{
	if(Empty())
		return;

	Elem *rElem = SearchElem(dItem);

	if(rElem == _first)
		RemoveFirst();
	else if(rElem == _last)
		RemoveLast();
	else
	{
		rElem->next->prev = rElem->prev;
		rElem->prev->next = rElem->next;
		delete rElem;
		_size--;
	}
	*_cashcorrect = false;
}

template <class T>
void List<T>::RemoveFirst(void)
{
	if(Empty())
		return;

	_first->makeFictitious();

	if(_first != _last)
		_first = _first->next;
	_size--;
	*_cashcorrect = false;
}

template <class T>
void List<T>::RemoveLast(void)
{
	if(Empty())
		return;

	_last->makeFictitious();

	if(_first != _last)
		_last = _last->prev;

	_size--;
	*_cashcorrect = false;
}

template <class T>
void List<T>::RemoveAll(void)
{
	if(Empty())
		return;

	Elem *now = _last = _first;
	_size = 0;
	while(!now->next->fictitious())
	{
		now->makeFictitious();
		now = now->next;
	}

	now->makeFictitious();
	
	*_cashcorrect = false;
}

template <class T>
void List<T>::Init(void)
{
	_first = 0;
	_last = 0;
	_size = 0;
	_cashe = 0;
	_casheSize = 0;
	_cashcorrect = new bool(false);
}

template <class T>
bool List<T>::CheckIndex(long index) const
{
	return index >= 0 && index < _size?true:false;
}

template <class T>
bool List<T>::Empty(void) const
{
	return _first?false:true;
}

template <class T>
void List<T>::SetCashe(void)
{
	delete[] _cashe;
	_casheSize = _size + _size;
	_cashe = new T*[_casheSize];
	*_cashcorrect = false;
	_cashe[0] = 0;
}

template <class T>
void List<T>::GetCashe(void) const
{
	Elem *temp = _first;
	long i = 0;
	while(temp != _last)
	{
		_cashe[i++] = temp->item;
		temp = temp->next;
	}
	_cashe[i] = temp->item;
	*_cashcorrect = true;
}

template <class T>
void List<T>::CheckCashe(void)
{
	if(_casheSize < _size)
		SetCashe();
}

template <class T>
T& List<T>::Top(void) const
{
	if(!_last->item)
		throw MyException("Stack is empty!!");
	return *_last->item;
}

template <class T>
void List<T>::Push(const T& myItem)
{
	Append(myItem);
}

template <class T>
T& List<T>::Pop(void)
{
	T temp = Get(_size-1);
	RemoveLast();
	return temp;
}

template <class T>
ListIterator<T> *List<T>::GetCorrectIterator(void)
{
	return new ListIterator<T>(this);
}


template <class T>
typename List<T>::Elem *List<T>::SearchElem(const T &searchItem)
{
	Elem<T> *now = _first;
	
	while(now!=_last)
	{
		if(*now->item==searchItem)
			return now;
		now = now->next;
	}

	if(*now->item==searchItem)
			return now;
	throw MyException("Item is excluded in list!");
}