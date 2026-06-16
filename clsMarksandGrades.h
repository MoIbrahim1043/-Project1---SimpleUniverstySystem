#pragma once
#include <iostream>
#include "clsString.h"
#include "clsInputValidate.h"
#include <fstream>
using namespace std;

class clsMarksandGrades
{
private:

	string _ID;
	float _Maths;
	float _Statics;
	float _Programming;
	float _Physics;
	float _Average;
	string _Grade;

	static clsMarksandGrades _ConvertDatalinetoObject(string line)
	{
		vector <string> vLine = clsString::splitstring(line, "#//#");
		return clsMarksandGrades(vLine[0], stof(vLine[1]), stof(vLine[2]), stof(vLine[3]), stof(vLine[4]), stof(vLine[5]), vLine[6]);
	}

	string _ConvertObjecttoDataLine(clsMarksandGrades& Student, string separator = "#//#")
	{
		string line = "";

		line += Student.getID() + separator;
		line += to_string(Student.getMaths()) + separator;
		line += to_string(Student.getStatics()) + separator;
		line += to_string(Student.getProgramming()) + separator;
		line += to_string(Student.getPhysics()) + separator;
		line += to_string(Student.getAverage()) + separator;
		line += Student.getGrade();

		return line;
	}

	static clsMarksandGrades _ReturnEmptyStudent(string ID)
	{
		return clsMarksandGrades(ID, 0, 0, 0, 0, 0, "");
	}

	void AddnewStudenttoFile()
	{
		fstream file;
		file.open("MarksandGrades.txt", ios::app);

		if (file.is_open())
		{
			string line = _ConvertObjecttoDataLine(*this);
			file << line << endl;
			file.close();
		}
	}

public:

	clsMarksandGrades(string ID, float maths, float statics, float programming, float physics, float Average, string Grade)
	{
		_ID = ID;
		_Maths = maths;
		_Statics = statics;
		_Programming = programming;
		_Physics = physics;
		_Average = Average;
		_Grade = Grade;
	}

	string getID()
	{
		return _ID;
	}

	void setMaths(float maths)
	{
		_Maths = maths;
	}

	float getMaths()
	{
		return _Maths;
	}

	void setStatics(float statics)
	{
		_Statics = statics;
	}

	float getStatics()
	{
		return _Statics;
	}

	void setProgramming(float programming)
	{
		_Programming = programming;
	}

	float getProgramming()
	{
		return _Programming;
	}

	void setPhysics(float physics)
	{
		_Physics = physics;
	}

	float getPhysics()
	{
		return _Physics;
	}

	void setAverage()
	{
		_Average = (_Maths + _Physics + _Programming + _Statics) / 4;
	}

	float getAverage()
	{
		return _Average;
	}

	void setGrade()
	{
		_Grade = STGrade(_Average);
	}

	string getGrade()
	{
		return _Grade;
	}

	static clsMarksandGrades Find(string ID)
	{
		fstream file;
		file.open("MarksandGrades.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsMarksandGrades Student = _ConvertDatalinetoObject(line);

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

	static string STGrade(float mark)
	{
		if (mark == 0) return "";

		string arrGrades[8] = { "A+" , "A-", "B+", "B-", "C","D","E","F" };

		return (mark >= 93) ? arrGrades[0] : (mark >= 87) ? arrGrades[1]
			: (mark >= 80) ? arrGrades[2] : (mark >= 72) ? arrGrades[3]
			: (mark >= 64) ? arrGrades[4] : (mark >= 57) ? arrGrades[5]
			: (mark >= 50) ? arrGrades[6] : arrGrades[7];
	}

	void Addnew()
	{
		AddnewStudenttoFile();
	}
};