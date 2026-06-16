#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsDoctor.h"
#include "clsStudent.h"
#include "clsInputValidate.h"
using namespace std;

class clsShowFindStudentscreen : protected clsScreen
{
private:

	static void _PrintstudentInfo(clsStudent& Student)
	{
		cout << "\n\t\t\t\t==========================================================";
		cout << "\n\t\t\t\tID        : " << Student.getID();
		cout << "\n\t\t\t\tFull name : " << Student.fullname();
		cout << "\n\t\t\t\tEmail     : " << Student.getemail();
		cout << "\n\t\t\t\tPhone     : " << Student.getphone();
		cout << "\n\t\t\t\tPassword  : " << Student.getPassword();
		cout << "\n\t\t\t\tPhase     : " << Student.getPhase();
		cout << "\n\t\t\t\t==========================================================\n\n";
	}

public:

	static void ShowFindStudentscreen()
	{
		clsScreen::_Drawscreenheader("Find Student");

		cout << "\nEnter ID : ";
		string id = clsInputValidate::readstring();

		if (clsStudent::isStudentExist(id))
		{
			clsStudent Student = clsStudent::Find(id);
			cout << "\n\t\t\t\tStudent Info : \n";
			_PrintstudentInfo(Student);
		}

		else
			cout << "\nStudent is not found.\n";
	}
};