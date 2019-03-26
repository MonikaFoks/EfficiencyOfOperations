#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>


struct ListElement {
	ListElement *next;
	ListElement *prev;
	int data;	//dane przechowywane w elemencie
};

class List {
public:
	ListElement *head;
	ListElement *tail;
	int n;		//ilo�� element�w listy

	List();
	virtual ~List();

	void push_front(int value);
	void push_back(int value);
	void pop(ListElement *element); //funkcja usuwaj�ca element na podstawie wska�nika
	void pop_head();
	void pop_tail();
	void show_list(); //wypisywanie listy
	void pop_random(int value); 
	void put_before(int element, int value); //dodaje po elemencie
	void read_file(int value); 
	ListElement *index_find(int index); //szuka na podstawie kolejno�ci w li�cie
	ListElement *find_element(int value); //znajdowanie warto�ci na podstawie wska�nika
};

#endif //LIST_H
