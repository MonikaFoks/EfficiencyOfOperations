#include "MyTime.h"
#include "List.h"
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

MyTime::MyTime()
{
}


MyTime::~MyTime()
{
}

void MyTime::start_time() {
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	start = read_QPC();
}

void MyTime::stop_time() {
	elapsed = read_QPC() - start;
	cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / freq << endl;
	cout << "Time [ms] =" << setprecision(0) << (1000.0*elapsed) / freq << endl;
	cout << "Time [us] =" << setprecision(3) << (1000000.0*elapsed) / freq << endl << endl;

	fstream file;
	file.open("pomiary.txt");
	if (file.good()) {
		file.seekg(0, file.end);
		file << (1000000.0*elapsed) / freq << endl;
		file.flush();
		file.close();
	}
}

long long int MyTime::read_QPC() {
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}