#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowDoctorInfoscreen.h"
#include "clsShowStudentsListscreen.h"
#include "clsShowFindStudentscreen.h"
#include "clsShowAddNewStudentscreen.h"
#include "clsDeleteStudentscreen.h"
class clsShowDoctorMainscreen : protected clsScreen
{
private:

	enum enDoctorMenuOption { ShowInfo = 1 , StudentsList = 2 , FindStudent = 3 , AddNewStudent = 4 , DeleteStudent = 5 , Logout = 6 };

	static short _Readmainmenuoption()
	{
		short Option = clsInputValidate::ReadNumberBetween<short>(1, 6, "\nWrong, please enter a number between 1 to 6 : ");
		return Option;
	}

	static void _ShowDoctorInfoscreen()
	{
		clsShowDoctorInfoscreen::ShowDoctorInfoscreen();
	}

	static void _ShowStudentsListscreen()
	{
		clsShowStudentsListscreen::ShowStudentsListscreen();
	}

	static void _ShowFindStudentscreen()
	{
		clsShowFindStudentscreen::ShowFindStudentscreen();
	}

	static void _ShowAddnewStudentscreen()
	{
		clsShowAddNewStudentscreen::ShowAddNewStudentScreen();
	}

	static void _ShowDeleteStudentscreen()
	{
		clsDeleteStudentscreen::ShowDeleteStudentscreen();
	}

	static void _GobacktoDoctorMainScreen()
	{
		cout << "\nPress any key to go back to main screen...";
		system("pause>0");
		ShowDoctorMainscreen();
	}

	static void _PerformDoctorMenuOption(enDoctorMenuOption enOption)
	{
		switch (enOption)
		{
		case enDoctorMenuOption::ShowInfo:
		{
			system("cls");
			_ShowDoctorInfoscreen();
			_GobacktoDoctorMainScreen();
			break;
		}
		case enDoctorMenuOption::StudentsList:
		{
			system("cls");
			_ShowStudentsListscreen();
			_GobacktoDoctorMainScreen();
			break;
		}
		case enDoctorMenuOption::FindStudent:
		{
			system("cls");
			_ShowFindStudentscreen();
			_GobacktoDoctorMainScreen();
			break;
		}
		case enDoctorMenuOption::AddNewStudent:
		{
			system("cls");
			_ShowAddnewStudentscreen();
			_GobacktoDoctorMainScreen();
			break;
		}
		case enDoctorMenuOption::DeleteStudent:
		{
			system("cls");
			_ShowDeleteStudentscreen();
			_GobacktoDoctorMainScreen();
			break;
		}
		case enDoctorMenuOption::Logout:
		{
			break;
		}
		}
	}

public:

	static void ShowDoctorMainscreen()
	{
		system("cls");
		clsScreen::_Drawscreenheader("Doctor Main Screen");

		cout << "\n";
		cout << setw(35) << "" << "========================================================\n";
		cout << setw(35) << "" << "    [1] Your Info\n";
		cout << setw(35) << "" << "    [2] Students List\n";
		cout << setw(35) << "" << "    [3] Find Student\n";
		cout << setw(35) << "" << "    [4] Add new Student\n";
		cout << setw(35) << "" << "    [5] Delete Student\n";
		cout << setw(35) << "" << "    [6] Logout\n";
		cout << setw(35) << "" << "========================================================\n";
		cout << setw(35) << "" << "Choose what do you want to do ( 1 to 6 ) : ";

		_PerformDoctorMenuOption(enDoctorMenuOption(_Readmainmenuoption()));
	}
};