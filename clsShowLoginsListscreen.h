#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
using namespace std;

class clsShowLoginsListscreen : protected clsScreen
{
private:

	struct stLoginData
	{
		string DateandTime;
		string Name;
		string ID;
		string Phone;
	};

	static stLoginData _ConvertDataLinetoStructure(string line, string parameter = "#//#")
	{
		vector <string> vTokens = clsString::splitstring(line, parameter);

		stLoginData Object;
		Object.DateandTime = vTokens.at(0);
		Object.Name = vTokens.at(1);
		Object.ID = vTokens.at(2);
		Object.Phone = vTokens.at(3);

		return Object;
	}

	static vector <stLoginData> _LoadDataFromFiletoVector()
	{
		fstream file;
		file.open("Logins.txt", ios::in);

		if (file.is_open())
		{
			string line;
			vector <stLoginData> vLogins;

			while (getline(file, line))
			{
				stLoginData Object = _ConvertDataLinetoStructure(line);
				vLogins.push_back(Object);
			}

			file.close();
			return vLogins;
		}
	}

	static vector <stLoginData> GetLogins()
	{
		return _LoadDataFromFiletoVector();
	}

	static void _Header()
	{
		cout << "\n\t________________________________________________________________________________________________\n";
		cout << "\t| " << setw(26) << left << "Date & Time";
		cout << "| " << setw(22) << left << "Name";
		cout << "| " << setw(15) << left << "ID/Username";
		cout << "| " << "Phone";
		cout << "\n\t________________________________________________________________________________________________\n";
	}

	static void _PrintoneLogin(stLoginData& oneLogin)
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

		vector <stLoginData> vLogins = GetLogins();

		_Header();

		if (vLogins.size() == 0)
			cout << "\n\t\t\tLogins will be here...\n";

		else
		{
			for (stLoginData& L : vLogins)
			{
				_PrintoneLogin(L);
				cout << endl;
			}
		}

		cout << "\n\t________________________________________________________________________________________________\n";
	}
};