#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsLogin.h"
#include <iomanip>
using namespace std;

class clsShowLoginsListscreen : protected clsScreen
{
private:

	static void _Header()
	{
		cout << "\n\t________________________________________________________________________________________________\n";
		cout << "\t| " << setw(26) << left << "Date & Time";
		cout << "| " << setw(22) << left << "Name";
		cout << "| " << setw(15) << left << "ID/Username";
		cout << "| " << "Phone";
		cout << "\n\t________________________________________________________________________________________________\n";
	}

	static void _PrintoneLogin(clsLogin::stLoginData& oneLogin)
	{
		cout << "\t| " << setw(26) << left << oneLogin.DateandTime;
		cout << "| " << setw(22) << left << oneLogin.Name;
		cout << "| " << setw(15) << left << oneLogin.ID;
		cout << "| " << oneLogin.Phone;
	}

public:

	static void ShowLoginsListscreen()
	{
		clsScreen::_Drawscreenheader("Logins list");

		vector <clsLogin::stLoginData> vLogins = clsLogin::GetLogins();

		_Header();

		if (vLogins.size() == 0)
			cout << "\n\t\t\tLogins will be here...\n";

		else
		{
			for (clsLogin::stLoginData& L : vLogins)
			{
				_PrintoneLogin(L);
				cout << endl;
			}
		}

		cout << "\n\t________________________________________________________________________________________________\n";
	}
};