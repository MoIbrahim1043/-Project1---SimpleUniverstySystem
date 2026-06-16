#pragma once
#include <iostream>
#include "Global.h"
#include "clsdate.h"
using namespace std;

static string iDorName()
{
	string Options[4] = { "","ID       : ","Username : ","Username : " };

	return Options[LoginOption];
}

static string PrintingidorName()
{
	switch (LoginOption)
	{
	case 1:
	{
		return CurrentStudent.getID();
		break;
	}
	case 2:
	{
		return CurrentDoctor.getUsername();
		break;
	}
	case 3:
	{
		return CurrentManager.getUsername();
		break;
	}
	default:
		return "";
		break;
	}
}

class clsScreen
{
protected:
	static void _Drawscreenheader(string Title, string subTitle = "")
	{
		cout << "\n\t\t\t________________________________________________________________________________\n";
		cout << "\n\t\t\t\t\t\t" << Title;
		if (subTitle != "")
		{
			cout << "\n\t\t\t\t\t\t" << subTitle;
		}
		cout << "\n\t\t\t________________________________________________________________________________\n\n";

		cout << "\t\t\t\t" << iDorName() << PrintingidorName();
		cout << "\n\t\t\t\tDate     : " << clsdate::date(clsdate());
	}
};