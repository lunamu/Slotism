#ifndef __SLOTS__H__
#define __SLOTS__H__


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Theme.h"
#include "Practice.h"
#include "Slot.h"
using namespace std;

//Main logic class, hold the most important concept in slotism: the slots.
//A slot is a time period that hold a theme.
//A theme is a topic/habit in time management context.
//A theme may be practiced differently. Each different practic of the theme is
//called a "practice"
//Function names speak for themselves.
class Slots
{
public:
	void ReadFromFile();
	void PrintActiveSlots()
	{
		for (list<Slot>::iterator it = slots.begin(); it != slots.end(); it++)
		{
			it->printActiveSlot();
			cout << endl;
		}
	}
	void PrintFullSlot()
	{
		for (list<Slot>::iterator it = slots.begin(); it != slots.end(); it++)
		{
			it->printFullSlot();
			cout << endl;
		}
	}
	void SaveToFile();
	void AddSlot(string startTime, string endTime, string theme, string firstPractice)
	{
		slots.push_back(Slot(startTime, endTime, theme, firstPractice));
	}
	void AddPractice(unsigned int slotNum, string practiceName)
	{
		list<Slot>::iterator it = slots.begin();
		for (int i = 0; i < slotNum; i++){ it++; }
		it->addPractice(practiceName);
	}
	void ModifyTheme(unsigned int slotNum, string newThemeName)
	{
		list<Slot>::iterator it = slots.begin();
		for (int i = 0; i < slotNum; i++){ it++; }
		it->setThemeName(newThemeName);
	}
	void ModifyPractice(unsigned int slotNum, unsigned int practiceNum, string newPracticeName)
	{
		list<Slot>::iterator it = slots.begin();
		advance(it, slotNum);
		list<Practice>::iterator itp = it->getPracticeList().begin();
		advance(itp, practiceNum);
		itp->setPracticeName(newPracticeName);
	}
	void DeleteSlot(unsigned int slotNum)
	{
		list<Slot>::iterator it = slots.begin(); 
		advance(it, slotNum);
		slots.erase(it);
	}
	void DeletePractice(unsigned int slotNum, unsigned int practiceNum)
	{
		list<Slot>::iterator it = slots.begin();
		advance(it, slotNum);
		list<Practice>::iterator itp = it->getPracticeList().begin();
		advance(itp, practiceNum);
		it->getPracticeList().erase(itp);
	}
	void SetActivePractice(unsigned int slotNum, unsigned int practiceNum)
	{
		list<Slot>::iterator it = slots.begin();
		advance(it, slotNum);
		list<Practice>::iterator itp = it->getPracticeList().begin();
		advance(itp, practiceNum);
		it->setActivePractice(practiceNum);
	}
private:
	list<Slot> slots;
};






#endif