#ifndef __THEME__H__
#define __THEME__H__


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <assert.h>
#include "Practice.h"
using namespace std;

//This is a class holding a theme.
//Notice that any theme will include a list of practice.
//Some practice will be active, because they are the focus of current theme.
//Some practice will be inactive, but may be activated someday.
//New themes will be added.
class Theme
{
public:
	Theme()
	{
		cout << "Theme constructor but why" << endl;
	}
	Theme(string themeName_)
	{
		themeName = themeName_;
		assert(!themeName_.empty());
		themeName = themeName_;
		symbol = themeName[0];
	}

	string getThemeName() const
	{
		return this->themeName;
	}
	void setThemeName(string themeName_)
	{
		themeName = themeName_;
	}
	
	void printTheme()
	{
		symbol = themeName[0];
		if (!themeName.empty())
			cout << themeName << ":" << "\"" << symbol << " \" ";
		else
			cout << "Empty Theme" << endl ;
	}


private:
	string themeName;
	string symbol;	//every theme has a symbol, for both symbolization & fast input.
};



#endif