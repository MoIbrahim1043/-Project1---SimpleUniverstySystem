#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsShowStudentInfoscreen.h"
#include "clsShowMarksandGradesscreen.h"
#include "clsShowUpdateInfoScreen.h"
using namespace std;

class clsShowStudentmainscreen : protected clsScreen
{
private:

	enum enStudentMenuOption { StudentInfo = 1 , StudentMarks = 2, UpdateInfo = 3 , Logout = 4 };

	static short _Readmainmenuoption()
	{
		short Option = clsInputValidate::ReadNumberBetween<short>(1, 4, "\nWrong, please enter a number between 1 to 4 : ");
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

	static void _ShowUpdateInfoScreen()
	{
		clsShowUpdateInfoScreen::ShowUpdateInfoScreen();
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
		case enStudentMenuOption::UpdateInfo:
		{
			system("cls");
			_ShowUpdateInfoScreen();
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
		cout << setw(35) << "" << "    [1] Student Info\n";
		cout << setw(35) << "" << "    [2] Student Marks\n";
		cout << setw(35) << "" << "    [3] Update Info\n";
		cout << setw(35) << "" << "    [4] Logout\n";
		cout << setw(35) << "" << "========================================================\n";
		cout << setw(35) << "" << "Choose what do you want to do ( 1 to 4 ) : ";

		_PerformStudentMenuOption(enStudentMenuOption(_Readmainmenuoption()));
	}
};