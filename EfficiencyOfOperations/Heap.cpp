#include "Heap.h"
#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

Heap::Heap()
{
	array = new int[0]; //inicjalizacja dynamicznej tablicy
	n = 0; //poczatkowo nie ma elementow
}

Heap::~Heap()
{
	delete[] array; //zwalnianie miejsca
}

void Heap::push(int value) //dodawanie elementu
{
	int child, parent;

	child = n++; //element zostanie dodany na koniec
	parent = (child - 1) / 2;//indeks jego rodzica
	int * new_array = new int[n - 1]; //zwiekszanie dynamicznej tablicy, takie jak w klasie Array

	for (int k = 0; k < n - 1; k++)
	{
		new_array[k] = array[k];
	}
	delete[] array;
	array = new int[n];
	for (int k = 0; k < n - 1; k++)
	{
		array[k] = new_array[k];
	}

	array[n - 1] = value;

	delete[] new_array;
	while (child > 0 && array[parent] < value) //znajdywanie indeksu dla nowego elementu
	{
		swap(array[child], array[parent]); //tak dlugo az rodzic elementu z obecnie wybranym idneksem jest mniejszy od niego, tak dlugo zamieniani sa oni miejscami i wybierana jest kolejna para
		child = parent;
		parent = (child - 1) / 2;
	}

	array[child] = value; //przypisanie wartosci do odpowiedzniego miejsca
}

void Heap::pop()//usuwanie elementu
{
	int root, left, value;

	if (n--) //zmniejszanie ilosci elementow
	{
		value = array[n];

		root = 0; //usuwanie jest wykonywanie od korzenia w dol
		left = 1; //dlatego poczotkowe indeksy to korzen i jego lewe dziecko

		while (left < n)// tak dlugo az nie skoncza sie elementy
		{
			if (left + 1 < n && array[left + 1] > array[left]) left++; //wybieramy ktore dziecko obecnego elementu jest wieksze
			if (value >= array[left]) break; //sprawdzamy czy osatnia wartosc jest na swoim miejscu 9wiesza od swoich dzieci)
			swap(array[root], array[left]); //jesli nie to zostaje zamieniona miejscami ze swoim dzieckiem
			root = left; //dobierana jest nastepna para
			left = 2 * left + 1;
		}

		array[root] = value; //ostatnia wartosc jest wpisywana w wybrane miejsce
		int * new_array = new int[n]; //w procesie tworzenia nowej tablicy wartosc z korzenia jest usuwana
		for (int i = 0; i < n; i++)
		{
			new_array[i] = array[i];
		}

		delete[] array;
		array = new int[n];

		for (int i = 0; i < n; i++)
		{
			array[i] = new_array[i];
		}

		delete[] new_array;
	}
}

void Heap::search(int val)
{
	if (n > 0)
	{
		int i;
		int * new_array = new int[n]; //tworzona jest tymczasowa tablica
		for (i = 0; array[0] != val && n > 0; i++) //wartosci z kopca sa usuwane i przepisywane do tymczasowej tablicy
		{
			new_array[i] = array[0];
			pop();
		}

		if (array[0] == val)//dzieje sie to tak dlugo az zostanie znaleziona wartosc badz usuniete zostana wszystkie elementy
		{
			cout << array[0] << endl;
		}

		for (int j = 0; j < i; j++)//elementy zostaja przywrocone
		{
			push(new_array[j]);
		}
	}
}

void Heap::print_heap()
{

	int j = 0;
	int level = 0;

	for (int i = 1; level < floor(log2(n)) + 1; i = 2 * i, level++) //wypisane zostaja elementy, algorytm wylicza ile ma ich byc na danym poziomie
	{
		for (int k = 0; k < i; j++, k++)
		{

			cout << array[j] << "  ";
			if (j == n - 1) //tutaj dalismy -1 bo pokazywalo smieci po dynamicznym dodawaniu
				break;
		}
		cout << endl;
	}
}

void Heap::pop_chosen(int val)//usuwanie wybranego elementu
{
	if (n > 0) //dzialanie takie samo jak wyszukiwanie, ale wartosc wyszukana tez jest usuwana
	{
		int i;
		int * new_array = new int[n];
		for (i = 0; array[0] != val && n > 0; i++)
		{
			new_array[i] = array[0];
			pop();
		}

		if (array[0] == val)
		{
			pop();
		}

		for (int j = 0; j < i; j++)
		{
			push(new_array[j]);
		}
	}
}

void Heap::read_file(int val)//wczytywanie danych z pliku, dzialanie takie jak w innych strukturach
{
	string stri;
	fstream file("20000.txt", ios::in);
	if (file.good())
	{
		for (int i = 0; i < val; i++)
		{
			getline(file, stri);
			char tmp[sizeof(stri)];
			strcpy_s(tmp, stri.c_str());
			int number = atoi(tmp);
			push(number);
		}
		file.close();
	}

}
void Heap::printBT(string sp, string sn, int v)
{
	string s;

	if (v < n)
	{
		s = sp;
		if (sn == "  ") s[s.length() - 2] = ' ';
		printBT(s + "  ", "  ", 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << array[v] << endl;

		s = sp;
		if (sn == "  ") s[s.length() - 2] = ' ';
		printBT(s + "  ", "  ", 2 * v + 1);
	}
}
