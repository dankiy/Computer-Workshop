// CW_17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "HashTable.h"
using namespace std;

int Menu(HashTable* HT)
{
	int menu;
	cout << "1 - Найти элемент" << endl;
	cout << "0 - Выход" << endl;
	cin >> menu;
	if (menu == 1)
	{
		int elem;
		cout << "Элемент: ";
		cin >> elem;
		if (HT->FindElement(elem))
			cout << "Элемент найден" << endl;
		else
			cout << "Элемент не найден" << endl;
		Menu(HT);
	}
	else if (menu == 0)
		return 1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char* file = "numbers.txt";
	ifstream reader(file);
	if (!reader)
	{
		cout << "Файла с таким названием не существует" << endl;
		system("pause");
		return 0;
	}
	else
	{
		int elem = 0, max, step;
		char temp;
		cout << "Максимальное значение строки в хэш-таблице: ";
		cin >> max;
		cout << "Шаг между строками в хэш-таблице: ";
		cin >> step;
		HashTable *HT = new HashTable(max, step);
		while ((temp = reader.get()) != EOF)
		{
			if (temp != '\n')
			{
				elem = elem * 10 + (int(temp) - 48);
			}
			else
			{
				cout << elem << endl;		
				HT->AddElement(elem);
				elem = 0;
			}
		}
		Menu(HT);
	}
}

