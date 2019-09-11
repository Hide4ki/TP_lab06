#pragma once

template <class T>
class Iterator
{
public:
	virtual void First(void) = 0;
	virtual void Next(void) = 0;
	virtual bool IsDone(void) const = 0;
	virtual T CurrentItem(void) const = 0;
protected:
	Iterator(void);
};

template <class T>
Iterator<T>::Iterator(void)
{
}