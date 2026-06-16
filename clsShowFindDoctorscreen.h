#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDoctor.h"
using namespace std;

class clsShowFindDoctorscreen : protected clsScreen
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

	static void ShowFindDoctorscreen()
	{
		clsScreen::_Drawscreenheader("Find Doctor");

		cout << "\nEnter username : ";
		string Uname = clsInputValidate::readstring();

		if (clsDoctor::isDoctorExist(Uname))
		{
			clsDoctor Doctor = clsDoctor::Find(Uname);
			cout << "\nDoctor info :\n";
			_PrintDoctorInfo(Doctor);
		}

		else
		{
			cout << "\nUser name [" << Uname << "] is not exist.\n";
		}
	}
};