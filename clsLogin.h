#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsStudent.h"
#include "clsDoctor.h"
#include "clsManager.h"
#include <vector>
#include <fstream>
#include "clsString.h"
#include "Global.h"
#include "clsShowStudentmainscreen.h"
#include "clsShowDoctorMainscreen.h"
using namespace std;

class clsLogin
{
private:

	struct stLoginData;

	static stLoginData _ConvertDataLinetoStructure(string line, string parameter = "#//#")
	{
		vector <string> vTokens = clsString::splitstring(line, parameter);

		stLoginData Object;
		Object.DateandTime = vTokens.at(0);
		Object.Name = vTokens.at(1);
		Object.ID = vTokens.at(2);
		Object.Phone = vTokens.at(3);

		return Object;
	}

	static vector <stLoginData> _LoadDataFromFiletoVector()
	{
		fstream file;
		file.open("Logins.txt", ios::in);

		if (file.is_open())
		{
			string line;
			vector <stLoginData> vLogins;

			while (getline(file, line))
			{
				stLoginData Object = _ConvertDataLinetoStructure(line);
				vLogins.push_back(Object);
			}

			file.close();
			return vLogins;
		}
	}

public:

	struct stLoginData
	{
		string DateandTime;
		string Name;
		string ID;
		string Phone;
	};

	static vector <stLoginData> GetLogins()
	{
		return _LoadDataFromFiletoVector();
	}

	static void PauseFunc()
	{
		cout << "\nPress any key to go to login page...\n";
		system("pause>0");
	}

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
};