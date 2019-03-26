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
	//list_menu.read_file(elements);
}