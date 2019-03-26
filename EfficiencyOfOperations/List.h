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
	int n;		//iloœæ elementów listy

	List();
	virtual ~List();

	void push_front(int value);
	void push_back(int value);
	void pop(ListElement *element); //funkcja usuwaj¹ca element na podstawie wskaŸnika
	void pop_head();
	void pop_tail();
	void show_list(); //wypisywanie listy
	void pop_random(int value); 
	void put_before(int element, int value); //dodaje po elemencie
	void read_file(int value); 
	ListElement *index_find(int index); //szuka na podstawie kolejnoœci w liœcie
	ListElement *find_element(int value); //znajdowanie wartoœci na podstawie wskaŸnika
};

#endif //LIST_H
