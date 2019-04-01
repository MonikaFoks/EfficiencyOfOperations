#include "Array.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <string>

using namespace std;

Array::Array()
{
	n = 0; //poczatkowo jest 0 danych
	array = new int[n]; //inicjalizacja dynamicznej tablicy
}

Array::~Array()
{
	delete[] array; //zwolnienie miejsca zajmowanego przez tablice
}


void Array::push_back(int element)
{
	n++; //zwiekszenie liczby elementow
	int * new_array = new int[n - 1]; //inicjalizacja tymczasowej tablicy

	for (int i = 0; i < n - 1; i++) //przepisywanie elementow z obecnej do tymczasowej tablicy
	{
		new_array[i] = array[i];
	}
	delete[] array; //zwalnianie miejsca na obecna tablice
	array = new int[n]; //tworzenie nowej, wiekszej tablicy
	array[n - 1] = element;// przypisywanie nowej zmiennej do odpowiedniego miejsca
	for (int i = 0; i < n - 1; i++)// przepisywanie starych zmiennych
	{
		array[i] = new_array[i];
	}

	delete[] new_array;//usuwanie tymczasowej tablicy
}

void Array::push_front(int element)
{
	n++;    //zwiekszenie liczby elementow
	int * new_array = new int[n - 1]; //inicjalizacja tymczasowej tablicy

	for (int i = 0; i < n - 1; i++) //przepisywanie elementow z obecnej do tymczasowej tablicy
	{
		new_array[i] = array[i];
	}
	delete[] array; //zwalnianie miejsca na obecna tablice
	array = new int[n]; //tworzenie nowej, wiekszej tablicy
	array[0] = element; // przypisywanie nowej zmiennej do odpowiedniego miejsca
	for (int i = 1; i < n; i++) // przepisywanie starych zmiennych
	{
		array[i] = new_array[i - 1];
	}
	delete[] new_array; //usuwanie tymczasowej tablicy
}

void Array::push_rand(int element, int index)
{
	n++; //zwiekszenie liczby elementow
	int * new_array = new int[n - 1]; //inicjalizacja tymczasowej tablicy


	for (int i = 0; i < n - 1; i++) //przepisywanie elementow z obecnej do tymczasowej tablicy
	{
		new_array[i] = array[i];
	}
	delete[] array; //zwalnianie miejsca na obecna tablice
	array = new int[n]; //tworzenie nowej, wiekszej tablicy

	for (int i = 0; i < n; i++) // przepisywanie starych zmiennych
	{
		if (i < index)
		{
			array[i] = new_array[i];
		}
		if (i == index)
		{
			array[i] = element; // przypisywanie nowej zmiennej do odpowiedniego miejsca
		}
		if (i > index)
		{
			array[i] = new_array[i - 1]; //przesuniecie sie na dalsze miejsca w wypadku znalezienia indeksu dla nowej zmiennej
		}
	}

	delete[] new_array; //usuwanie tymczasowej tablicy
}

int Array::search(int element)
{
	int index = -1; //pocatkowo wyszukany indeks to -1
	for (int i = 0; i < n; i++) //szukanie lelementu zadanego argumentem funkcji
	{
		if (array[i] == element)
		{
			index = i; //jesli element zostanie znaleziony to zwracany jest jego indeks
			break;
		}
	}

	return index; //jesli nie zostanie znaleziony to zwracane jest -1
}

void Array::pop_tail()
{
	if (n > 0) //jesli sa elementy w tablicy
	{
		n--; //zmniejszenie ilosci elementow
		int * new_array= new int[n]; //inicjalizacja tymczasowej tablicy
		for (int i = 0; i < n; i++) //przepisywanie elementow z obecnej do tymczasowej tablicy
		{
			new_array[i] = array[i];
		}

		delete[] array; //zwalnianie miejsca na obecna tablice
		array = new int[n]; //tworzenie nowej, wiekszej tablicy

		for (int i = 0; i < n; i++)  // przepisywanie starych zmiennych
		{
			array[i] = new_array[i];
		}

		delete[] new_array; //usuwanie tymczasowej tablicy
	}
}



void Array::pop_head()
{
	if (n > 0) //jesli sa elementy w tablicy
	{
		n--; //zmniejszenie ilosci elementow
		int * new_array = new int[n]; //inicjalizacja tymczasowej tablicy
		for (int i = 0; i < n; i++) //przepisywanie elementow z obecnej do tymczasowej tablicy
		{
			new_array[i] = array[i + 1];
		}

		delete[] array; //zwalnianie miejsca na obecna tablice
		array = new int[n]; //tworzenie nowej, wiekszej tablicy

		for (int i = 0; i < n; i++) // przepisywanie starych zmiennych
		{
			array[i] = new_array[i];
		}

		delete[] new_array; //usuwanie tymczasowej tablicy
	}

}

void Array::pop_rand(int element)
{
	if (n > 0) //jesli sa elementy w tablicy
	{
		int index = search(element); //wyszukiwanie indeksu usuwanego elementu
		n--;                    //zmniejszenie ilosci elementow
		int * new_array = new int[n]; //inicjalizacja tymczasowej tablicy
		for (int i = 0; i < n; i++) //przepisywanie elementow z obecnej do tymczasowej tablicy
		{
			if (i < index)
			{
				new_array[i] = array[i]; //ominiety zostaje indeks usuwanego elementu
			}
			if (i >= index)
			{
				new_array[i] = array[i + 1];
			}

		}
		delete[] array; //zwalnianie miejsca na obecna tablice
		array = new int[n]; //tworzenie nowej, wiekszej tablicy

		for (int i = 0; i < n; i++) // przepisywanie starych zmiennych
		{
			array[i] = new_array[i];
		}

		delete[] new_array; //usuwanie tymczasowej tablicy
	}
}

void Array::show_array() //wypisywanie wartosci z tablicy przy uzyciu petli for
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void Array::read_file(int value) //wczytywanie z pliku wartosci
{
	string str;
	fstream file("20000.txt", ios::in); //otwieranie pliku
	if (file.good())
	{
		for (int i = 0; i < value; i++)//wczytywanie okreslonej ilosci zmiennych
		{
			getline(file, str); //wczytywanie zmiennej w formie string
			char temp[sizeof(str)];
			strcpy_s(temp, str.c_str());
			int number = atoi(temp);// zamiana zmiennej na int
			push_front(number);//wpisywanie zmiennej do tablicy
		}
		file.close(); //zamykanie pliku
	}

}


