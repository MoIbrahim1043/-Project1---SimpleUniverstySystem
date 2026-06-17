#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsShowStudentInfoscreen.h"
#include "clsShowMarksandGradesscreen.h"
using namespace std;

class clsShowStudentmainscreen : protected clsScreen
{
private:

	enum enStudentMenuOption { StudentInfo = 1 , StudentMarks = 2, Logout = 3 };

	static short _Readmainmenuoption()
	{
		short Option = clsInputValidate::ReadNumberBetween<short>(1, 3, "\nWrong, please enter a number between 1 to 3 : ");
		return Option;
	}

	static void _ShowStudentInfoScreen()
	{
		clsShowStudentInfoscreen::ShowStudentinfoscreen();
	}

	static void _ShowMarksandGradesscreen()
	{
		clsShowMarksandGradesscreen::ShowMarksandGradesscreen();
	}

	static void _GoBackToStudentMainScreen()
	{
		cout << "\nPress any key to go back to main screen...";
		system("pause>0");
		ShowStudentmainscreen();
	}

	static void _PerformStudentMenuOption(enStudentMenuOption enOption)
	{
		switch (enOption)
		{
		case enStudentMenuOption::StudentInfo:
		{
			system("cls");
			_ShowStudentInfoScreen();
			_GoBackToStudentMainScreen();
			break;
		}
		case enStudentMenuOption::StudentMarks:
		{
			system("cls");
			_ShowMarksandGradesscreen();
			_GoBackToStudentMainScreen();
			break;
		}
		case enStudentMenuOption::Logout:
		{
			break;
		}
		}
	}

public:

	static void ShowStudentmainscreen()
	{
		system("cls");
		clsScreen::_Drawscreenheader("Student Main Screen");
		
		cout << "\n";

		cout << setw(35) << "" << "========================================================\n";
		cout << setw(35) << "" << "\t\t\tMain Menu\n";
		cout << setw(35) << "" << "========================================================\n";
		cout << setw(35) << "" << "    [1] Student Info\n";
		cout << setw(35) << "" << "    [2] Student Marks\n";
		cout << setw(35) << "" << "    [3] Logout\n";
		cout << setw(35) << "" << "========================================================\n";
		cout << setw(35) << "" << "Choose what do you want to do ( 1 to 3 ) : ";

		_PerformStudentMenuOption(enStudentMenuOption(_Readmainmenuoption()));
	}
};