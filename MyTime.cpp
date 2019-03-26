#include "MyTime.h"
#include <Windows.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

MyTime::MyTime() {}
MyTime::~MyTime() {}

void MyTime::time_start() {
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = read_QPC();
}