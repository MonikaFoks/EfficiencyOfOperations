#ifndef ARRAY_H
#define ARRAY_H


class Array
{
public:
	int * array;			//wskaznik na dynamiczna tablice
	int n;					//ilosc elementow w tablicy
	Array();
	virtual ~Array();
	void push_back(int element);		//dodaj element z przodu
	void push_front(int element);		//dodaj element z tylu
	void push_rand(int element, int index);	//dodaj element w losowe miejsce
	void pop_tail();						//usun element z przodu
	void pop_head();						//usun element z tylu
	void pop_rand(int element);					//usun element z losowego miejsca
	int search(int element);					//znajdz element
	void show_array();						// wypisz tablice
	void read_file(int value);				// wczytaj dane z pliku
};

#endif // ARRAY_H#pragma once
