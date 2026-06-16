#pragma once
#include <iostream>
#include "clsLogin.h"
#include "clsScreen.h"
#include "clsStudent.h"
#include "clsDoctor.h"
#include "clsManager.h"
#include "clsShowManagerMainscreen.h"
using namespace std;

class clsShowLoginscreen : protected clsScreen
{
private:

	static void ManagerLogin()
	{
		cout << "\nEnter Username : ";
		string Username = clsInputValidate::readstring();

		cout << "\nEnter Password : ";
		string Password = clsInputValidate::readstring();

		CurrentManager = clsManager::Find(Username, Password);

		if (CurrentManager.isEmpty())
		{
			LoginOption = 0;
			cout << "\nInvalid Username/Password\n";
			clsLogin::PauseFunc();
		}

		else
		{
			CurrentManager.AddtoLoginlist();
			clsShowManagerMainscreen::ShowManagerMainscreen();
		}
	}

	enum enLoginOption { Student = 1 , Doctor = 2 , Manager = 3 };

	static short _Readmainmenuoption()
	{
		short Option = clsInputValidate::ReadNumberBetween<short>(1, 3, "\nWrong, please enter a number between 1 to 3 : ");
		LoginOption = Option;
		return Option;
	}

	static void _PerformLoginOption(enLoginOption Option)
	{
		switch (Option)
		{
		case enLoginOption::Student:
		{
			clsLogin::StudentLogin();
			CurrentStudent = clsStudent::Find("");
			break;
		}
		case enLoginOption::Doctor:
		{
			clsLogin::DoctorLogin();
			CurrentDoctor = clsDoctor::Find("");
			break;
		}
		case enLoginOption::Manager:
		{
			ManagerLogin();
			CurrentManager = clsManager::Find("");
			break;
		}
		}
	}

public:

	static void Login()
	{
		system("cls");
		clsScreen::_Drawscreenheader("Login Screen");

		cout << "\nAre you [1] Student , [2] Doctor , [3] Manager  : ";

		_PerformLoginOption(enLoginOption(_Readmainmenuoption()));
	}
	
};