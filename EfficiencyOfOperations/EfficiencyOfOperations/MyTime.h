#pragma once
#ifndef MYTIME_H
#define MYTIME_H

class MyTime
{
public:
	MyTime();
	virtual ~MyTime();
	long long int freq, start, elapsed;
	long long int read_QPC();
	void start_time();
	void stop_time();

protected:
private:
};

#endif MYTIME_H

