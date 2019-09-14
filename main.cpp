#include <iostream>
#include "MyException.h"
#include "Note.h"
#include "List.h"
#include "IteratorPtr.h"
#include "WorkEnd.h"

using namespace std;

void sortList(List<Note*>&);

typedef enum {ADD, FIND, SORT, SHOW, END} COMMAND;

int main(void)
{	
	cout << "Good day!=)" << endl;
	List<Note*> *ListNote = new List<Note*>(1);
	while(1)
	{
		try
		{
			int command;
			string surname;
			Note *tmp;
			cout << "Input command(" \
			<<ADD<< " - add obj; "\
			<<FIND<<" - find obj; "\
			<<SORT<<" - sort; "\
			<<SHOW<<" - show; "\
			<<END<< " - end work.)" << endl;

			cin >> command;

			switch((COMMAND)command)
			{
				case ADD:
					cout << "Selected add" << endl;
					tmp = new Note;
					cin >> *tmp;
					ListNote->Append(tmp); 
					break;
				case FIND:
					cout << "Selected find" << endl;
					cout << "Input surname:" << endl;
					cin >> surname;
					{
						Note *myNote = new Note(surname);
						IteratorPtr<Note*> i(ListNote->GetCorrectIterator());
						for(i->First(); !i->IsDone(); i->Next()) 
						{
							if(*i->CurrentItem()==*myNote)
							{
								cout << *i->CurrentItem();
								break;
							}
						}
						if(i->IsDone())
							cout << "Data this person is not found" << endl;
						delete myNote;
					}
					break;
				case SORT:
					cout << "Selected sort" << endl;
					sortList(*ListNote);
				  break;
				case SHOW:
					cout << "Selected show" << endl;
					{
						IteratorPtr<Note*> i(ListNote->GetCorrectIterator());
						for(i->First(); !i->IsDone(); i->Next()) 
						{
							cout << *i->CurrentItem() << "  ";
						}
					}
				  break;
				case END:
					cout << "Selected end" << endl;
					throw WorkEnd();
					break;
			}
		}
		catch(MyException& e)
		{
			cout << "Error: " << e << endl;
		}
		catch(WorkEnd& e)
		{
			cout << e << endl;
			break;
		}
		catch(...)
		{
			cout << "Error!!! Input don't correct, repeat input!!" << endl;
		}
	}
	IteratorPtr<Note*> i(ListNote->GetCorrectIterator());
	for(i->First(); !i->IsDone(); i->Next()) 
	{
		delete i->CurrentItem();
	}
	delete ListNote;
	system("pause");
	return 0;
}

void sortList(List<Note*>&myList)
{
	int min;
	for(int i = 0;i<myList.Count()-1;i++) 
	{
		for(int j = i + 1;j<myList.Count();j++) 
		{
			if(*myList.Get(i) > *myList.Get(j))
				myList.Swap(myList.Get(i),myList.Get(j));
		}
	}
}
