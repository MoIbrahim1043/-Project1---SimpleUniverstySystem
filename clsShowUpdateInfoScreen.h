#pragma once
#include <iostream>
#include <iomanip>
#include "clsStudent.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsShowUpdateInfoScreen : protected clsScreen
{
private:

	static void _ReadStudentInfo(clsStudent& Student)
	{
		cout << "\nEnter first name : ";
		Student.setfirstname(clsInputValidate::readstring());

		cout << "\nEnter last name : ";
		Student.setlastname(clsInputValidate::readstring());

		cout << "\nEnter E-mail : ";
		Student.setemail(clsInputValidate::readstring());

		cout << "\nEnter phone number : ";
		Student.setphone(clsInputValidate::readstring());

		cout << "\nEnter password : ";
		Student.setPassword(clsInputValidate::readstring());
	}

public:

	static void ShowUpdateInfoScreen()
	{
		clsScreen::_Drawscreenheader("Update Student info");

		_ReadStudentInfo(CurrentStudent);

		if (CurrentStudent.UpdateInfo())
		{
			cout << "\nStudent info has updated succesfully :-)\n";
		}

	}
};