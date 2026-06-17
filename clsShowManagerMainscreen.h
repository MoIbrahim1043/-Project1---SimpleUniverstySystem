#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsShowManagerInfoscreen.h"
#include "clsShowFindStudentscreen.h"
#include "clsShowFindDoctorscreen.h"
#include "clsShowStudentsListscreen.h"
#include "clsShowDoctorsListscreen.h"
#include "clsShowAddNewStudentscreen.h"
#include "clsDeleteStudentscreen.h"
#include "clsShowDeleteDoctorscreen.h"
#include "clsShowLoginsListscreen.h"
#include "clsShowUpdateInfoScreen.h"
using namespace std;

class clsShowManagerMainscreen : protected clsScreen
{
private:

	enum enMainMenuOption { ManagerInfo = 1 , FindStudent = 2 , FindDoctor = 3 
		, StudentsList = 4 , DoctorsList = 5 , AddStudent = 6 , AddDoctor = 7 
		, DeleteStudent = 8 , DeleteDoctor = 9 , UpdateInfo = 10 , LoginsList = 11 , Logout = 12 };

	static short _Readmainmenuoption()
	{
		short Option = clsInputValidate::ReadNumberBetween<short>(1, 12, "\nWrong, please enter a number between 1 to 12 : ");
		return Option;
	}

	static void _ShowManagerInfoscreen()
	{
		clsShowManagerInfoscreen::ShowManagerInfoscreen();
	}

	static void _ShowFindStudentscreen()
	{
		clsShowFindStudentscreen::ShowFindStudentscreen();
	}

	static void _ShowFindDoctorscreen()
	{
		clsShowFindDoctorscreen::ShowFindDoctorscreen();
	}

	static void _ShowStudentsListscreen()
	{
		clsShowStudentsListscreen::ShowStudentsListscreen();
	}

	static void _ShowDoctorsListscreen()
	{
		clsShowDoctorsListscreen::ShowDoctorsListscreen();
	}

	static void _ShowAddnewStudentscreen()
	{
		clsShowAddNewStudentscreen::ShowAddNewStudentScreen();
	}

	static void _ShowDeleteStudentscreen()
	{
		clsDeleteStudentscreen::ShowDeleteStudentscreen();
	}

	static void _ShowDeleteDoctorscreen()
	{
		clsShowDeleteDoctorscreen::ShowDeleteDoctorscreen();
	}

	static void _ShowUpdateStudentscreen()
	{
		clsShowUpdateInfoScreen::ShowUpdateInfoScreen();
	}

	static void _ShowLoginsListscreen()
	{
		clsShowLoginsListscreen::ShowLoginsListscreen();
	}

	static void _GobacktoManagerMenu()
	{
		cout << "\nPress any key to go back to main menu...";
		system("pause>0");

		ShowManagerMainscreen();
	}

	static void _PerformMainMenuOption(enMainMenuOption enOption)
	{
		switch (enOption)
		{
		case enMainMenuOption::ManagerInfo:
		{
			system("cls");
			_ShowManagerInfoscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::FindStudent:
		{
			system("cls");
			_ShowFindStudentscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::FindDoctor:
		{
			system("cls");
			_ShowFindDoctorscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::StudentsList:
		{
			system("cls");
			_ShowStudentsListscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::DoctorsList:
		{
			system("cls");
			_ShowDoctorsListscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::AddStudent:
		{
			system("cls");
			_ShowAddnewStudentscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::AddDoctor:
		{
			system("cls");

			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::DeleteStudent:
		{
			system("cls");
			_ShowDeleteStudentscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::DeleteDoctor:
		{
			system("cls");
			_ShowDeleteDoctorscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::UpdateInfo:
		{
			system("cls");
			_ShowUpdateStudentscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::LoginsList:
		{
			system("cls");
			_ShowLoginsListscreen();
			_GobacktoManagerMenu();
			break;
		}
		case enMainMenuOption::Logout:
		{
			break;
		}
		}
	}

public:

	static void ShowManagerMainscreen()
	{
		system("cls");

		clsScreen::_Drawscreenheader("Manager main screen");

		cout << "\n";
		cout << setw(35) << "" << "=========================================================\n";
		cout << setw(35) << "" << "\t\t\tMain Menu\n";
		cout << setw(35) << "" << "=========================================================\n";
		cout << setw(35) << "" << "      [1] Your Info\n";
		cout << setw(35) << "" << "      [2] Find Student\n";
		cout << setw(35) << "" << "      [3] Find Doctor\n";
		cout << setw(35) << "" << "      [4] Students list\n";
		cout << setw(35) << "" << "      [5] Doctors list\n";
		cout << setw(35) << "" << "      [6] Add Student\n";
		cout << setw(35) << "" << "      [7] Add Doctor\n";
		cout << setw(35) << "" << "      [8] Delete Student\n";
		cout << setw(35) << "" << "      [9] Delete Doctor\n";
		cout << setw(35) << "" << "      [10] Update Student\n";
		cout << setw(35) << "" << "      [11] Logins list\n";
		cout << setw(35) << "" << "      [12] Logout\n";
		cout << setw(35) << "" << "=========================================================\n";
		cout << setw(35) << "" << "Choose what do you want to do ( 1 to 12 ) : ";

		_PerformMainMenuOption(enMainMenuOption(_Readmainmenuoption()));
	}
};