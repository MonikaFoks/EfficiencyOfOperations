#pragma once
#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
public:
	long long int freq, start, elapsed;
	MyTime();
	virtual ~MyTime();
	void time_start();
	void time_stop();
	long long int read_QPC();
};

#endif // !MYTIME_H

