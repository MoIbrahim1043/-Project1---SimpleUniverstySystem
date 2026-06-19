#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDoctor.h"
#include <iomanip>
using namespace std;

class clsShowDoctorsListscreen : protected clsScreen
{
private:

	static void _Header()
	{
		cout << "\n\t_________________________________________________________________________________________________\n";
		cout << "\t| " << setw(12) << left << "Username";
		cout << "| " << setw(25) << left << "Name";
		cout << "| " << setw(15) << left << "Phone";
		cout << "| " << "Salary";
		cout << "\n\t_________________________________________________________________________________________________\n";
	}

	static void _PrintoneDoctor(clsDoctor& Doctor)
	{
		cout << "\t| " << setw(12) << left << Doctor.getUsername();
		cout << "| Dr." << setw(22) << left << Doctor.fullname();
		cout << "| " << setw(15) << left << Doctor.getphone();
		cout << "| " << Doctor.getSalary();
	}

public:

	static void ShowDoctorsListscreen()
	{
		vector <clsDoctor> vDoctors = clsDoctor::GetDoctorslist();
		string subTitle = to_string(vDoctors.size()) + " Doctor(s)";

		clsScreen::_Drawscreenheader("Doctors list", subTitle);
		_Header();

		if (vDoctors.size() == 0)
		{
			cout << "\nNo doctors right now...\n";
		}

		else
		{
			for (clsDoctor& D : vDoctors)
			{
				_PrintoneDoctor(D);
				cout << endl;
			}
		}

		cout << "\t_________________________________________________________________________________________________\n";
	}
};