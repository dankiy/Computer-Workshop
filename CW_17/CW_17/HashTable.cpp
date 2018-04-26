#include "stdafx.h"
#include "HashTable.h"

HashTable::HashTable()
{
	Step = 50;
	Max = 10000;
	*Table = new Element[Max / Step + 1];
}

HashTable::HashTable(int max, int step)
{	
	Step = step;
	Max = max;
	Table = new Element*[Max / Step + 1];
	for (int i = 0; i <= Max / Step; i++)
		Table[i] = NULL;
}
	
HashTable::~HashTable()
{
	delete[] Table;
}

void HashTable::AddElement(int num)
{
	static int index = (num < Max ? num / Step : Max / Step); //индекс в массиве
	Element* elem = new Element;
	elem->Content = num;
	if (Table[index] == NULL)
	{
		elem->Next = NULL;
		Table[index] = elem;
	}
	else
	{
		elem->Next = Table[index];
		Table[index] = elem;
	}
}

bool HashTable::FindElement(int num)
{
	static int index = (num < Max ? num / Step : Max / Step); //индекс в массиве
	Element* temp = Table[index];
	while (temp != NULL)
	{
		if (temp->Content == num)
			return true;
		else
			temp = temp->Next;
	}
	return false;
}