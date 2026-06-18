#pragma once
#include <iostream>
#include "clsPerson.h"
#include <fstream>
#include "clsInputValidate.h"
#include "clsdate.h"
using namespace std;

class clsStudent : public clsPerson
{
private:

	string _ID;
	string _Password;
	short _Phase;
	bool _MarkedforDelete = false;

	static clsStudent _ConvertDatalinetoObject(string line)
	{
		vector <string> vLine = clsString::splitstring(line, "#//#");
		return clsStudent(vLine[0], vLine[1], vLine[2], vLine[3], vLine[4], vLine[5], stoi(vLine[6]));
	}

	static clsStudent _ReturnEmptyStudent(string ID)
	{
		return clsStudent("", "", "", "", ID, "", 0);
	}

	 string _ConvertObjecttoDataLine(clsStudent &Student, string separator = "#//#")
	{
		string line = "";

		line += Student.getfirstname() + separator;
		line += Student.getlastname() + separator;
		line += Student.getemail() + separator;
		line += Student.getphone() + separator;
		line += Student.getID() + separator;
		line += Student.getPassword() + separator;
		line += to_string(Student.getPhase());

		return line;
	}

	static vector <clsStudent> _LoaddataFromFiletoVector()
	{
		fstream file;
		file.open("Students.txt", ios::in);

		if (file.is_open())
		{
			string line;
			vector <clsStudent> vStudents;

			while (getline(file, line))
			{
				clsStudent Student = _ConvertDatalinetoObject(line);
				vStudents.push_back(Student);
			}

			file.close();
			return vStudents;
		}
	}

	void _LoaddataFromVectortoFile(vector <clsStudent>& vStudents)
	{
		fstream file;
		file.open("Students.txt", ios::out);

		if (file.is_open())
		{
			string line;

			for (clsStudent& S : vStudents)
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

	void AddnewStudenttoFile()
	{
		fstream file;
		file.open("Students.txt", ios::app);

		if (file.is_open())
		{
			string line = _ConvertObjecttoDataLine(*this);
			file << line << endl;
			file.close();
		}
	}

	string _PrepareLoginline(string Parameter = "#//#")
	{
		return clsdate::DateandTime() + Parameter + fullname() + Parameter + _ID + Parameter + getphone();
	}

public:

	clsStudent(string firstname, string lastname, string email, string phone, string id, string password, short phase)
		: clsPerson(firstname, lastname, email, phone)
	{
		_ID = id;
		_Password = password;
		_Phase = phase;
	}

	string getID()
	{
		return _ID;
	}

	void setPassword(string password)
	{
		_Password = password;
	}

	string getPassword()
	{
		return _Password;
	}

	void setPhase(short phase)
	{
		_Phase = phase;
	}

	short getPhase()
	{
		return _Phase;
	}

	bool getMarkedforDelete()
	{
		return _MarkedforDelete;
	}

	bool isEmpty()
	{
		if (getemail() == "" && getphone() == "" && _Phase == 0)
		{
			return true;
		}

		return false;
	}

	static clsStudent Find(string ID, string Password)
	{
		fstream file;
		file.open("Students.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsStudent Student = _ConvertDatalinetoObject(line);

				if (Student.getID() == ID && Student.getPassword() == Password)
				{
					file.close();
					return Student;
				}
			}

			file.close();
			return _ReturnEmptyStudent(ID);
		}
	}

	static clsStudent Find(string ID)
	{
		fstream file;
		file.open("Students.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsStudent Student = _ConvertDatalinetoObject(line);

				if (Student.getID() == ID)
				{
					file.close();
					return Student;
				}
			}

			file.close();
			return _ReturnEmptyStudent(ID);
		}
	}

	bool UpdateInfo()
	{
		vector <clsStudent> vStudents = _LoaddataFromFiletoVector();

		for (clsStudent& S : vStudents)
		{
			if (S.getID() == _ID)
			{
				S = *this;
				break;
			}
		}

		_LoaddataFromVectortoFile(vStudents);
		return true;
	}

	static vector <clsStudent> getStudents()
	{
		return _LoaddataFromFiletoVector();
	}

	static bool isStudentExist(string ID)
	{
		clsStudent Student = clsStudent::Find(ID);
		return (!Student.isEmpty()) ? true : false;
	}

	void Addnew()
	{
		AddnewStudenttoFile();
	}

	void Delete()
	{
		vector <clsStudent> vStudents = _LoaddataFromFiletoVector();

		for (clsStudent& S : vStudents)
		{
			if (_ID == S.getID())
			{
				S._MarkedforDelete = true;
				break;
			}
		}

		_LoaddataFromVectortoFile(vStudents);
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