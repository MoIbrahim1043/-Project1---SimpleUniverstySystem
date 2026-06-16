#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsManager.h"
using namespace std;

class clsShowManagerInfoscreen : protected clsScreen
{
private:

	static void _PrintManagerInfo(clsManager& Manager)
	{
		cout << "\n\t\t\t\t==========================================================";
		cout << "\n\t\t\t\tFull name : " << Manager.fullname();
		cout << "\n\t\t\t\tEmail     : " << Manager.getemail();
		cout << "\n\t\t\t\tPhone     : " << Manager.getphone();
		cout << "\n\t\t\t\tPassword  : " << Manager.getPassword();
		cout << "\n\t\t\t\tSalary    : " << Manager.getSalary();
		cout << "\n\t\t\t\t==========================================================\n\n";
	}

public:

	static void ShowManagerInfoscreen()
	{
		clsScreen::_Drawscreenheader("Your Info");

		_PrintManagerInfo(CurrentManager);
	}
};