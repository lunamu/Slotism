#ifndef __SLOT__H__
#define __SLOT__H__

#include <iostream>
#include <string>
#include <list>
#include "Time.h"
using namespace std;

//This class is used to hold slot
//slot bind "time","theme" and "practice" together.
class Slot
{
public:
	Slot(string startTime_, string endTime_, string theme_, string firstPractice_) 
	{
		theme.setThemeName(theme_);
		practice.push_back(Practice(firstPractice_));
		activePractice = practice.begin();
	}
	void printActiveSlot()
	{
		//TODO: print time
		theme.printTheme();
		cout << "  ";
		//activePractice->printPractice();
	}
	void printFullSlot()
	{
		//TODO: print time
		theme.printTheme();
		cout << "  ";
		for (list<Practice>::iterator it = practice.begin(); it != practice.end(); it++)
		{
			cout << "                ";
			it->printPractice();
			cout << endl;
		}
	}
	void printStartTime(){ startTime.printTime(); }
	void printEndTime(){ endTime.printTime(); }
	void setActivePractice(string preName)
	{
		for (list<Practice>::iterator it = practice.begin(); it != practice.end(); it++)
		{
			std::size_t found = it->getPracticeName().find(preName);
			if (found != string::npos)
			{
				activePractice = it;
			}
		}
	}
	void setActivePractice(int practiceNum)
	{
		activePractice = practice.begin();
		advance(activePractice, practiceNum);
	}
	void addPractice(string practiceName)
	{
		practice.push_back(Practice(practiceName));
	}
	void setThemeName(string themeName)
	{
		this->theme.setThemeName(themeName);
	}
	list<Practice>& getPracticeList()
	{
		return this->practice;
	}
private:
	Time startTime;
	Time endTime;
	Theme theme;
	list<Practice> practice;
	list<Practice>::iterator activePractice;
};





#endif