#pragma once
#include <iostream>
#include "clsDoctor.h"
#include "clsScreen.h"
using namespace std;

class clsShowDoctorInfoscreen : protected clsScreen
{
private:

	static void _PrintDoctorInfo(clsDoctor& Doctor)
	{
		cout << "\n\t\t\t\t==========================================================";
		cout << "\n\t\t\t\tFull name : " << Doctor.fullname();
		cout << "\n\t\t\t\tEmail     : " << Doctor.getemail();
		cout << "\n\t\t\t\tPhone     : " << Doctor.getphone();
		cout << "\n\t\t\t\tPassword  : " << Doctor.getPassword();
		cout << "\n\t\t\t\tSalary    : " << Doctor.getSalary();
		cout << "\n\t\t\t\t==========================================================\n\n";
	}

public:

	static void ShowDoctorInfoscreen()
	{
		clsScreen::_Drawscreenheader("Your Info");

		_PrintDoctorInfo(CurrentDoctor);
	}
};