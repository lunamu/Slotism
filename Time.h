#ifndef __TIME__H__
#define __TIME__H__


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Time
{
public:
	Time()
	{
		cout << "time constructor but why" << endl;
	}
	Time(int hour_, int minute_, int second_) 
	{
		hour = hour_;
		minute = minute_;
		second = second_;
	}
	Time(string time)
	{
		hour = time[0] + time[1];
		minute = time[2] + time[3];
		second = time[4] + time[5];
	}
	void printTime()
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
	void setTime(int hour_, int minute_, int second_)
	{
		hour = hour_;
		minute = minute_;
		second = second_;
	}
private:
	int hour;
	int minute;
	int second;
};



#endif