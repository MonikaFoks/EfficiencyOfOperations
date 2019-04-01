#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Heap
{
public:
	int *array; //wskaznik na dynamiczna tablice
	int n; //ilosci elementow w kopcu
	Heap();
	virtual ~Heap();
	void push(int value); //dodawanie do kopca
	void pop(); //usuwanie z kopca
	void search(int val); //wyszukiwanie elementu
	void print_heap(); //wypisywanie kopca
	void pop_chosen(int val); //usuwanie wybranego elementu
	void read_file(int val); //wczytywanie wartosci z pliku
	void printBT(string sp, string sn, int v);

};

#endif // HEAP_H
