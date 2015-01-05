#ifndef __PRACTICE__H__
#define __PRACTICE__H__

#include <iostream>
#include <string>
using namespace std;

class Practice
{
public:
	Practice(string practiceName)
	{
		practiceName_ = practiceName;
	}
	string getPracticeName() 
	{
		return this->practiceName_;
	}
	void setPracticeName(string newPracticeName)
	{
		practiceName_ = newPracticeName;
	}
	void printPractice()
	{
		if (!practiceName_.empty())
			cout << practiceName_ ;
		else
			cout << "Empty Practice" << endl;
	}
private:
	string practiceName_;
};




#endif