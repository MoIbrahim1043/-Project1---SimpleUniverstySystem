#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsInputValidate.h"
#include <fstream>
#include <vector>
#include "clsString.h"
using namespace std;

class clsDoctor : public clsPerson
{
private:

	string _Username;
	string _Password;
	double _Salary;
	bool _Markfordelete = false;

	static clsDoctor _ConvertDatalinetoObject(string line)
	{
		vector <string> vLine = clsString::splitstring(line, "#//#");
		return clsDoctor(vLine[0], vLine[1], vLine[2], vLine[3], vLine[4], vLine[5], stod(vLine[6]));
	}

	string _ConvertObjecttoDataLine(clsDoctor& Doctor, string separator = "#//#")
	{
		string line = "";

		line += Doctor.getfirstname() + separator;
		line += Doctor.getlastname() + separator;
		line += Doctor.getemail() + separator;
		line += Doctor.getphone() + separator;
		line += Doctor.getUsername() + separator;
		line += Doctor.getPassword() + separator;
		line += to_string(Doctor.getSalary());

		return line;
	}


	static clsDoctor _ReturnEmptyDoctor(string Username)
	{
		return clsDoctor("", "", "", "", Username, "", 0);
	}

	static vector <clsDoctor> _LoaddataFromFiletoVector()
	{
		fstream file;
		file.open("Doctors.txt", ios::in);

		if (file.is_open())
		{
			string line;
			vector <clsDoctor> vDoctors;

			while (getline(file, line))
			{
				clsDoctor Doctor = _ConvertDatalinetoObject(line);
				vDoctors.push_back(Doctor);
			}

			file.close();
			return vDoctors;
		}
	}

	void _LoaddataFromVectortoFile(vector <clsDoctor>& vDoctors)
	{
		fstream file;
		file.open("Doctors.txt", ios::out);

		if (file.is_open())
		{
			string line;

			for (clsDoctor& S : vDoctors)
			{
				if (S.getMarkedforDelete() == false)
				{
					line = _ConvertObjecttoDataLine(S);
					file << line << endl;
				}
			}

			file.close();
		}
	}

	string _PrepareLoginline(string Parameter = "#//#")
	{
		return clsdate::DateandTime() + Parameter + fullname() + Parameter + _Username + Parameter + getphone();
	}


public:

	clsDoctor(string firstname, string lastname, string email, string phone, string username, string password, double salary)
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

	bool getMarkedforDelete()
	{
		return _Markfordelete;
	}

	bool isEmpty()
	{
		if (getemail() == "" && getphone() == "" && _Password == "" && _Salary == 0)
		{
			return true;
		}

		return false;
	}

	static clsDoctor Find(string Username, string Password)
	{
		fstream file;
		file.open("Doctors.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsDoctor Doctor = _ConvertDatalinetoObject(line);

				if (Doctor.getUsername() == Username && Doctor.getPassword() == Password)
				{
					file.close();
					return Doctor;
				}
			}

			file.close();
			return _ReturnEmptyDoctor(Username);
		}
	}

	static clsDoctor Find(string Username)
	{
		fstream file;
		file.open("Doctors.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsDoctor Doctor = _ConvertDatalinetoObject(line);

				if (Doctor.getUsername() == Username)
				{
					file.close();
					return Doctor;
				}
			}

			file.close();
			return _ReturnEmptyDoctor(Username);
		}
	}

	static bool isDoctorExist(string Username)
	{
		fstream file;
		file.open("Doctors.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsDoctor Doctor = _ConvertDatalinetoObject(line);

				if (Doctor.getUsername() == Username)
				{
					file.close();
					return true;
				}
			}

			file.close();
			return false;
		}

	}

	static vector <clsDoctor> GetDoctorslist()
	{
		return _LoaddataFromFiletoVector();
	}

	void Delete()
	{
		vector <clsDoctor> vDoctors = _LoaddataFromFiletoVector();

		for (clsDoctor& D : vDoctors)
		{
			if (D.getUsername() == _Username)
			{
				D._Markfordelete = true;
				break;
			}
		}

		_LoaddataFromVectortoFile(vDoctors);
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