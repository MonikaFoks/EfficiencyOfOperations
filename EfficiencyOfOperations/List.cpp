#include "List.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

List::List() {
	n = 0; //pocz�tkowa konfiguracja - brak warto�ci
	head = NULL;
	tail = NULL;
}

List::~List() {
	while (head)
		pop_head(); //usuwanie element�w, dop�ki istniej�
}

void List::push_front(int value) {
	n++;
	ListElement *p = new ListElement; //wska�nik na nowy element listy
	p->data = value; //nadawanie warto�ci p
	p->prev = NULL; //element jest na przodzie, wi�c nic nie ma przed nim
	p->next = head; //po nim jest poprzedni pierwszy
	head = p; //obecnym pierwszym jest nowy element

	if (p->next) //je�li dodany element ma nast�pnika...
		p->next->prev = p; //...nast�pny wskazuje na niego jako na poprzednika
	else
		tail = p; //w przeciwnym wypadku ten element jest te� ostatni
}

void List::push_back(int value) {
	n++;
	ListElement *p = new ListElement;
	p->data = value;
	p-> prev = tail;
	p->next = NULL;
	tail = p;

	if (p->prev)
		p->prev->next = p;
	else
		head = p;
}

void List::pop(ListElement *element) {
	if (element) {
		if (element->prev) //je�li element posiada poprzednika...
			element->prev->next = element->next; //...poprzednik musi wskazywa� na element b�d�cy po usuwanym jako na swojego nast�pc�
		else
			head = element->next; //

		if (element->next)
			element->next->prev = element->prev;
		else
			tail = element->prev;

		delete element;
		n--; //zmniejszamy licznik element�w
	}
}

void List::pop_head() {
	pop(head);
}

void List::pop_tail() {
	pop(tail);
}

void List::show_list() {
	ListElement *p;
	p = head;
	while (p) {
		cout << " " << p->data;
		p = p->next;
	}
	cout << endl;
}

ListElement *List::find_element(int value) {
	ListElement *p = head;
	while (p) {
		if (p->data == value) {
			cout << "Element was found." << endl;
			return p;
		}
		p = p->next;
	}
	return NULL; //je�li nic nie znaleziono
}