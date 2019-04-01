#pragma once
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "MyTime.h"

class Menu {
public:
	bool exit;
	char var;

	Menu();
	virtual ~Menu();

	void show();
	void show_array();
	void show_list();
	void show_heap();
	void show_tree();
};
#endif // MENU_H
