#pragma once
#include <iostream>
#include "clsStudent.h"
#include "clsScreen.h"
#include "Global.h"
using namespace std;

class clsShowStudentInfoscreen : protected clsScreen
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

	static void ShowStudentinfoscreen()
	{
		clsScreen::_Drawscreenheader("Student info screen");

		_PrintstudentInfo(CurrentStudent);
	}
};