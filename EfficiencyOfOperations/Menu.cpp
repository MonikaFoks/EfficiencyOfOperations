#include "MyTime.h"
#include "List.h"
#include "Array.h"
#include "Heap.h"
#include "Menu.h"
#include "Tree.h"
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
		case '1':
			show_array();
			break;

		case '2': 
			show_list();
			break;

		case '3':
			show_heap();
			break;
		
		case '4':
			show_tree();
			break;
			//TODO: dopisaæ SWITCHE!
		}
	}
}

void Menu::show_array() //opcje dotyczace tablicy
{
	bool exita = true;
	int vara;
	int number_el;
	Array arrm;
	cout << "How many elements do you want?: " << endl;
	cin >> number_el;
	arrm.read_file(number_el);
	while (exita)
	{
		cout << "ARRAY" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "Choose action: " << endl;
		cout << "1) Add elements in the front" << endl;
		cout << "2) Add elements in the back" << endl;
		cout << "3) Add an element in random place" << endl;
		cout << "4) Delete elements from the front" << endl;
		cout << "5) Delete elements from the back" << endl;
		cout << "6) Delete random elements" << endl;
		cout << "7) Find the element" << endl;
		cout << "8) Show the list" << endl;
		cout << "9) EXIT" << endl;
		cin >> vara;

		switch (vara)
		{
		case 1:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to add?: " << endl;
			cin >> temp;
			time.start_time(); //wy wypadku operacji dodawania, usuwania oraz wyszukiwania elementow w kazdej strukturze liczony jest jaczs wykonania operacji
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)//generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
				{
					int rnd_num = rand() % 30000;
					arrm.push_front(rnd_num);
				}
			}
			time.stop_time();
		}
		break;

		case 2:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to add?: " << endl;
			cin >> temp;
			time.start_time(); //generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					int rnd_num = rand() % 30000;
					arrm.push_back(rnd_num);
				}
			}
			time.stop_time();
		}
		break;

		case 3:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to add?: " << endl;
			cin >> temp;
			time.start_time(); //generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					int rnd_num = rand() % 30000;
					int rnd1 = rand() % number_el;
					arrm.push_rand(rnd_num, rnd1);
				}
			}
			time.stop_time();
		}
		break;

		case 4:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to remove?: " << endl;
			cin >> temp;
			time.start_time(); //ilosc usuwanych liczb jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					arrm.pop_head();
				}
			}
			time.stop_time();
		}
		break;

		case 5:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to remove?: " << endl;
			cin >> temp;
			time.start_time(); //ilosc usuwanych liczb jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					arrm.pop_tail();
				}
			}
			time.stop_time();
		}
		break;

		case 6:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to remove?: " << endl;
			cin >> temp;
			time.start_time(); //ilosc usuwanych liczb jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					int rnd = rand() % 30000;
					arrm.pop_rand(rnd);
				}
			}
			time.stop_time();
		}
		break;

		case 7:
		{
			MyTime time;
			int temp;
			cout << "Which element do you want to find ?: " << endl;
			cin >> temp;
			time.stop_time(); //uzytkownik podaje wyszukiwana wartosc
			arrm.search(temp);
			time.stop_time();
		}
		break;

		case 8:
		{
			arrm.show_array();
		}
		break;

		case 9:
		{
			exita = false;
		}
		break;
		}
	}
}

void Menu::show_list() //opcje dotyczace listy
{
	bool exitl = true;
	int varl;
	int number_el;
	List listm;
	cout << "How many elements of list do you want?: " << endl;
	cin >> number_el;
	listm.read_file(number_el);

	while (exitl)
	{
		cout << "LIST" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "Choose action: " << endl;
		cout << "1) Add elements in the front" << endl;
		cout << "2) Add elements in the back" << endl;
		cout << "3) Add an element in random place" << endl;
		cout << "4) Delete elements from the front" << endl;
		cout << "5) Delete elements from the back" << endl;
		cout << "6) Delete random elements" << endl;
		cout << "7) Find the element" << endl;
		cout << "8) Show the list" << endl;
		cout << "9) EXIT" << endl;
		cin >> varl;

		switch (varl)
		{
		case 1:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to add?: " << endl;
			cin >> temp;
			time.start_time(); //generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					int rnd = rand() % 30000;
					listm.push_front(rnd);
				}
			}
			time.stop_time();
		}
		break;

		case 2:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to add?: " << endl;
			cin >> temp;
			time.start_time(); //generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					int rnd = rand() % 30000;
					listm.push_back(rnd);
				}
			}
			time.stop_time();
		}
		break;

		case 3:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to add?: " << endl;
			cin >> temp;
			time.start_time();
			for (int i = 0; i < temp; i++) //generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			{
				int rnd = rand() % 30000;
				int rnd1 = rand() % listm.n;
				listm.put_before(rnd1, rnd);
			}
			time.stop_time();
		}
		break;

		case 4:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to remove?: " << endl;
			cin >> temp;
			time.start_time(); //uzytkownik podaje liczbe usuwanych elementow
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					listm.pop_head();
				}
			}
			time.stop_time();
		}
		break;

		case 5:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to remove?: " << endl;
			cin >> temp;
			time.start_time();  //uzytkownik podaje liczbe usuwanych elementow
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					listm.pop_tail();
				}
			}
			time.stop_time();
		}
		break;

		case 6:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to remove?: " << endl;
			cin >> temp;
			time.start_time();  //uzytkownik podaje liczbe usuwanych elementow
			for (int i = 0; i < temp; i++)
			{
				int rnd = rand() % number_el;
				listm.pop_random(rnd);
			}
			time.stop_time();
		}
		break;

		case 7:
		{
			listm.show_list();
		}
		break;

		case 8:
		{
			MyTime time;
			int temp;
			cout << "Which element do you want to find?" << endl;
			cin >> temp; //uzytkownik podaje wyszukiwany element
			time.start_time(); 
			listm.find_element(temp);
			time.stop_time();
		}
		break;

		case 9:
		{
			exitl = false;
		}
		break;
		}
	}
}

void Menu::show_heap() //opcje dotyczace kopca
{
	bool exith = true;
	int varh;
	int number_el;
	Heap heapm;
	cout << "How many values do you want in the heap?: " << endl;
	cin >> number_el;
	heapm.read_file(number_el);

	while (exith)
	{
		cout << "HEAP" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "Choose action: " << endl;
		cout << "1) Add elements"<< endl;
		cout << "2) Delete elements" << endl;
		cout << "3) Delete choosen element" << endl;
		cout << "4) Show the heap" << endl;
		cout << "5) Find the element" << endl;
		cout << "6) EXIT" << endl;
		cin >> varh;

		switch (varh)
		{
		case 1:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to add?: " << endl;
			cin >> temp;
			time.start_time(); //generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					int rnd = rand() % 30000;
					heapm.push(rnd);
				}
			}
			time.stop_time();
		}
		break;

		case 2:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to remove?: " << endl;
			cin >> temp; //uzytkownik podaje liczbe usuwanych wartosci
			if (temp > number_el)
			{
				temp = number_el;
			}
			time.start_time();
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					heapm.pop();
				}
			}
			time.stop_time();
		}
		break;

		case 3:
		{
			MyTime time;
			int temp;
			cout << "Which element do you want to remove?: " << endl;
			cin >> temp;
			time.start_time(); //istnieje mozliwosc usuniecia wybranego elementu
			heapm.pop_chosen(temp);
			time.stop_time();
		}
		break;

		case 4:
		{
			heapm.printBT("  ", "  ", 0);
		}
		break;

		case 5:
		{
			MyTime time;
			int temp;
			cout << "Which element do you want to find?" << endl;
			cin >> temp;
			time.start_time(); //uzytkownik podaje wyszukiwany element
			heapm.search(temp);
			time.stop_time();
		}
		break;

		case 6:
		{
			exith = false;
		}
		break;
		}
	}
}

void Menu::show_tree() //opcje dotyczace drzewa czerwono czarnego
{
	bool exitt = true;
	int vart;
	int number_el;
	Tree treem;
	cout << "How many values you want in the tree?: " << endl;
	cin >> number_el;
	treem.read_file(number_el);

	while (exitt)
	{
		cout << "RB TREE" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "Choose action: " << endl;
		cout << "1) Add elements" << endl;
		cout << "2) Delete elements" << endl;
		cout << "3) Delete choosen element" << endl;
		cout << "4) Show the tree" << endl;
		cout << "5) Find the element" << endl;
		cout << "6) EXIT" << endl;
		cin >> vart;

		switch (vart)
		{
		case 1:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to add?: " << endl;
			cin >> temp;
			time.start_time(); //generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					int rnd = rand() % 30000;
					treem.insert(rnd);
				}
			}
			time.stop_time();
		}
		break;

		case 2:
		{
			MyTime time;
			int temp;
			cout << "How many elements do you want to remove?: " << endl;
			cin >> temp;
			time.start_time(); //uzytkownik podaje liczbe usuwanych wartosci
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					treem.remove_node(treem.root);
				}
			}
			time.stop_time();
		}
		break;

		case 3:
		{
			MyTime time;
			int temp;
			cout << "Which element do you want to remove?: " << endl;
			cin >> temp;
			time.start_time(); //istnieje mozliwosc usuniecia wybranego elementu
			treem.remove_node(treem.find_element(temp));
			time.stop_time();
		}
		break;

		case 4:
		{
			treem.printTree("", "", treem.root);
		}
		break;

		case 5:
		{
			MyTime time;
			int temp;
			cout << "Which element do you want to find?" << endl;
			cin >> temp;
			time.start_time(); //uzytkownik podaje wyszukiwany element
			treem.find_element(temp);
			time.stop_time();
		}
		break;

		case 6:
		{
			exitt = false;
		}
		break;
		}
	}
}