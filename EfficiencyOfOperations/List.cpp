#include "List.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

List::List() {
	n = 0; //pocz¹tkowa konfiguracja - brak wartoœci
	head = NULL;
	tail = NULL;
}

List::~List() {
	while (head)
		pop_head(); //usuwanie elementów, dopóki istniej¹
}

void List::push_front(int value) {
	n++;
	ListElement *p = new ListElement; //wskaŸnik na nowy element listy
	p->data = value; //nadawanie wartoœci p
	p->prev = NULL; //element jest na przodzie, wiêc nic nie ma przed nim
	p->next = head; //po nim jest poprzedni pierwszy
	head = p; //obecnym pierwszym jest nowy element

	if (p->next) //jeœli dodany element ma nastêpnika...
		p->next->prev = p; //...nastêpny wskazuje na niego jako na poprzednika
	else
		tail = p; //w przeciwnym wypadku ten element jest te¿ ostatni
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
		if (element->prev) //jeœli element posiada poprzednika...
			element->prev->next = element->next; //...poprzednik musi wskazywaæ na element bêd¹cy po usuwanym jako na swojego nastêpcê
		else
			head = element->next; //

		if (element->next)
			element->next->prev = element->prev;
		else
			tail = element->prev;

		delete element;
		n--; //zmniejszamy licznik elementów
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
	return NULL; //jeœli nic nie znaleziono
}