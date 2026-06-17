#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDoctor.h"
#include "clsScreen.h"
using namespace std;

class clsShowAddDoctorscreen : protected clsScreen
{
private:

	static void _ReadDoctorInfo(clsDoctor& Doctor)
	{
		cout << "\nEnter First name : ";
		Doctor.setfirstname(clsInputValidate::readstring());

		cout << "\nEnter Last name : ";
		Doctor.setlastname(clsInputValidate::readstring());

		cout << "\nEnter E-mail : ";
		Doctor.setemail(clsInputValidate::readstring());

		cout << "\nEnter phone : ";
		Doctor.setphone(clsInputValidate::readstring());

		cout << "\nEnter Password : ";
		Doctor.setPassword(clsInputValidate::readstring());

		cout << "\nEnter salary : ";
		Doctor.setsalary(clsInputValidate::ReadNumber<double>());
	}

public:

	static void ShowAddnewDoctorscreen()
	{
		clsScreen::_Drawscreenheader("Add Doctor Screen");

		cout << "\nEnter Username : ";
		string Username = clsInputValidate::readstring();

		while (clsDoctor::isDoctorExist(Username))
		{
			cout << "\nExist, Enter another Username : ";
			string Username = clsInputValidate::readstring();
		}

		clsDoctor Doctor = clsDoctor::Find(Username);
		_ReadDoctorInfo(Doctor);

		Doctor.AddNew();
		cout << "\nDoctor added succesfully :-)\n";
	}
};