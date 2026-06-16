#pragma once
#include <iostream>
#include "clsPerson.h"
#include <fstream>
#include <vector>
#include "clsdate.h"
using namespace std;

class clsManager : public clsPerson
{
private:

	string _Username;
	string _Password;
	double _Salary;

	static clsManager _ConvertDatalinetoObject(string line)
	{
		vector <string> vLine = clsString::splitstring(line, "#//#");
		return clsManager(vLine[0], vLine[1], vLine[2], vLine[3], vLine[4], vLine[5], stod(vLine[6]));
	}

	static clsManager _ReturnEmptyManager(string Username)
	{
		return clsManager("", "", "", "", Username, "", 0);
	}

	string _PrepareLoginline(string Parameter = "#//#")
	{
		return clsdate::DateandTime() + Parameter + fullname() + Parameter + _Username + Parameter + getphone();
	}

public:

	clsManager(string firstname, string lastname, string email, string phone, string username, string password, double salary)
		: clsPerson(firstname, lastname, email, phone)
	{
		_Username = username;
		_Password = password;
		_Salary = salary;
	}

	void setsalary(double salary)
	{
		_Salary = salary;
	}

	string getUsername()
	{
		return _Username;
	}

	string getPassword()
	{
		return _Password;
	}

	double getSalary()
	{
		return _Salary;
	}

	bool isEmpty()
	{
		if (getemail() == "" && getphone() == "" && _Password == "" && _Salary == 0)
		{
			return true;
		}

		return false;
	}

	static clsManager Find(string Username, string Password)
	{
		fstream file;
		file.open("Manager.txt", ios::in);

		if (file.is_open())
		{
			string line;
			getline(file, line);
			clsManager Manager = _ConvertDatalinetoObject(line);

			if (Manager.getUsername() == Username && Manager.getPassword() == Password)
			{
				file.close();
				return Manager;
			}

			file.close();
			return _ReturnEmptyManager(Username);
		}
	}

	static clsManager Find(string Username)
	{
		fstream file;
		file.open("Manager.txt", ios::in);

		if (file.is_open())
		{
			string line;
			getline(file, line);
			
				clsManager Manager = _ConvertDatalinetoObject(line);

				if (Manager.getUsername() == Username)
				{
					file.close();
					return Manager;
				}
			

			file.close();
			return _ReturnEmptyManager(Username);
		}
	}
	
	void AddtoLoginlist()
	{
		fstream file;
		file.open("Logins.txt", ios::app);

		if (file.is_open())
		{
			string line = _PrepareLoginline();
			file << line << endl;

			file.close();
		}
	}
};