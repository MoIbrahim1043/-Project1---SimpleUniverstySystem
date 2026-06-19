#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsStudent.h"
#include "clsDoctor.h"
#include "clsManager.h"
#include "clsMarksandGrades.h"
#include <vector>
#include <fstream>
#include "clsString.h"
#include "Global.h"
#include "clsShowStudentmainscreen.h"
#include "clsShowDoctorMainscreen.h"
#include "clsShowManagerMainscreen.h"
using namespace std;

class clsLogin
{
private:

	static void PauseFunc()
	{
		cout << "\nPress any key to go to login page...\n";
		system("pause>0");
	}

public:


	static void StudentLogin()
	{
		cout << "\nEnter ID : ";
		string ID = clsInputValidate::readstring();

		cout << "Enter Password : ";
		string Password = clsInputValidate::readstring();

		CurrentStudent = clsStudent::Find(ID, Password);

		if (!CurrentStudent.isEmpty())
		{
			CurrentStudent.AddtoLoginlist();
			CurrentStudentMandG = clsMarksandGrades::Find(ID);
			clsShowStudentmainscreen::ShowStudentmainscreen();
		}

		else
		{
			LoginOption = 0;
			cout << "\nInvalid ID/Password ..\n";
			PauseFunc();
		}
	}

	static void DoctorLogin()
	{
		cout << "\nEnter Username : ";
		string Username = clsInputValidate::readstring();

		cout << "\nEnter Password : ";
		string Password = clsInputValidate::readstring();

		CurrentDoctor = clsDoctor::Find(Username, Password);

		if (CurrentDoctor.isEmpty())
		{
			LoginOption = 0;
			cout << "\nInvalid Username/Password\n";
			PauseFunc();
		}

		else
		{
			CurrentDoctor.AddtoLoginlist();
			clsShowDoctorMainscreen::ShowDoctorMainscreen();
		}
	}

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
};