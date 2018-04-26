#pragma once
class HashTable
{
private:
	int Step;
	int Max;
	struct Element
	{
		int Content;
		Element* Next;
	};
	Element* *Table;
public:
	HashTable();
	HashTable(int max, int step);
	~HashTable();
	void AddElement(int num);
	bool FindElement(int num);
};

