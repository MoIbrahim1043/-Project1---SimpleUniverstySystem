#pragma once
#include <iostream>
#include "clsDoctor.h"
#include "clsStudent.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsMarksandGrades.h"
using namespace std;

class clsShowStudentsListscreen : protected clsScreen
{
private:

	static void _Header()
	{
		cout << "\t_________________________________________________________________________________________________________\n";
		cout << "\t| " << setw(10) << left << "ID";
		cout << "| " << setw(25) << left << "Name";
		cout << "| " << setw(14) << left << "Phone";
		cout << "| " << setw(10) << left << "Average";
		cout << "| " << "Grade\n";
		cout << "\t_________________________________________________________________________________________________________\n";
	}

	static void _PrintOneStudent(clsStudent& Student, clsMarksandGrades &MarksandGrades)
	{
		cout << "\t| " << setw(10) << left << Student.getID();
		cout << "| " << setw(25) << left << Student.fullname();
		cout << "| " << setw(14) << left << Student.getphone();
		cout << "| " << setw(10) << left << MarksandGrades.getAverage();
		cout << "| " << MarksandGrades.getGrade();
	}

public:

	static void ShowStudentsListscreen()
	{
		vector <clsStudent> vStudents = clsStudent::getStudents();
		string subTitle = to_string(vStudents.size()) + " Student(s)";
		clsScreen::_Drawscreenheader("Students List", subTitle);

		_Header();

		if (vStudents.size() == 0)
		{
			cout << "\nNo students exist right now...\n";
		}

		else
		{
            for (clsStudent& S : vStudents)
		    {
			    clsMarksandGrades Grades = clsMarksandGrades::Find(S.getID());

			    _PrintOneStudent(S, Grades);
				cout << endl;
		    }
		}

		cout << "\t_________________________________________________________________________________________________________\n";
	}
};