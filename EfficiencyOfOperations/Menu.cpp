#include "MyTime.h"
#include "List.h"
#include "Menu.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

Menu::Menu() {
	exit = true;
}

Menu::~Menu() {}

void Menu::show() {
	while (exit) {
		cout << "MENU" << endl;
		cout << "------------------------------------" << endl;
		cout << "Please choose a structure:" << endl;
		cout << "1) Array \n2) List \n3) Heap \n4) Tree \n5) EXIT" << endl;

		cin >> var;

		switch (var) {
		case '2': 
			show_list();
			break;

			//TODO: dopisaæ SWITCHE!
		}
	}
}

void Menu::show_list() {
	bool exit_list = true;
	int var_list;
	int elements;
	List list_menu;

	cout << "How many values of list do you want?:" << endl;
	cin >> elements;
	list_menu.read_file(elements);

	while (exit_list) {
		cout << "LIST" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "Choose action: " << endl;
		cout << "1) Add elements in the front" << endl;
		cout << "2) Add elements in the back" << endl;
		cout << "3) Add an element in random place" << endl;
		cout << "4) Delete elements from the front" << endl;
		cout << "5) Delete elements from the back" << endl;
		cout << "6) Delete random elements" << endl;
		cout << "7) Show the list" << endl;
		cout << "8) Find the element" << endl;
		cout << "9) EXIT" << endl;
		cin >> var_list;

		switch (var_list) {
		case 1:
		{
			MyTime time;

		}
		}
	}
}