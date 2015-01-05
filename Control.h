#ifndef __CONTROL__H__
#define __CONTROL__H__

#include <iostream>
#include <string>
#include "Slots.h"
using namespace std;

void WelcomMessage()
{
	cout << "********************** Welcom **********************" << endl;
	cout << "This is Slotism, a brand new way to manage your life" << endl;
	cout << "*************  Prototyped by Wang Tong *************" << endl;
	cout << "******** I have plan to implement it on iOS ********" << endl;
	cout << "****************************************************" << endl;
}

void Menu()
{
	cout << "1. Show my current slots" << endl;
	cout << "2. Show full slots "  << endl;
	cout << "3. Add a slot " << endl;
	cout << "4. Add a practice " << endl;
	cout << "5. Delete a slot or practice" << endl;
	cout << "6. Set active practice" << endl;
	cout << "7. Exit" << endl;
	cout << "Choose : " << endl;
}


//This class is used to hold main loop, run program, accept input, and display output.
class Control
{
public:
	Control()
	{
		
	}
	void mainLoop();
private:
	Slots s;
};


void Control::mainLoop()
{
	WelcomMessage();
	int selector = 0;
	while (1)
	{
		Menu();
		cin >> selector;
		switch (selector)
		{
			case(1) :
			{
				s.PrintActiveSlots();
				continue;
			}
			case(2) :
			{
				s.PrintFullSlot();
				continue;
			}
			case(3) :
			{
				cout << "Insert start time / end time / theme name / first practice : " << endl;
				string startTime, endTime, themeName, firstPractice;
				cin >> startTime >> endTime >> themeName >> firstPractice;
				s.AddSlot(startTime, endTime, themeName, firstPractice);
				s.PrintActiveSlots();
				continue;
			}
			case(4) :
			{
				cout << "Insert the slot num you want to add new practice in : " << endl;
				int slotNum;
				cin >> slotNum;
				cout << "Insert the practice name : " << endl;
				string practiceName;
				cin >> practiceName;
				s.AddPractice(slotNum, practiceName);
				continue;
			}
			case(5) :
			{
				int slotOrPractice = 0;
				int num1, num2;
				cout << "Slot or practice? 0/1 : " << endl;
				cin >> slotOrPractice;
				if (!slotOrPractice)
				{
					cout << "Insert slot number : " << endl;
					cin >> num1;
					s.DeleteSlot(num1);
				}
				else
				{
					cout << "Insert slot number & practice number : " << endl;
					cin >> num1 >> num2;
					s.DeletePractice(num1, num2);
				}
				continue;
			}
			case(6) :
			{
				cout << "Insert the slot num & practice num" << endl;
				int num1, num2;
				cin >> num1 >> num2;
				s.SetActivePractice(num1, num2);
				continue;
			}
			case(7) :
			{
				exit(0);
			}
			default:
				continue;
		}
	}
}



#endif