#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDoctor.h"
using namespace std;

class clsShowDeleteDoctorscreen : protected clsScreen 
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

	static void ShowDeleteDoctorscreen()
	{
		clsScreen::_Drawscreenheader("Delete Doctor");

		cout << "\nEnter doctor username : ";
		string Username = clsInputValidate::readstring();

		if (clsDoctor::isDoctorExist(Username))
		{
			clsDoctor Doctor = clsDoctor::Find(Username);
			_PrintDoctorInfo(Doctor);
			char c;

			cout << "\nAre you sure you want to delete this doctor ? ( Y/N ) : ";
			cin >> c;

			if (toupper(c) == 'Y')
			{
				Doctor.Delete();
				cout << "\nDoctor deleted succesfully :-)\n";
			}
		}

		else
			cout << "\nUsername [" << Username << "] is not found.\n";
	}
};

