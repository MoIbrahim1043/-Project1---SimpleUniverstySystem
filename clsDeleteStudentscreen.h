#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsStudent.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteStudentscreen : protected clsScreen
{
private:

	static void _PrintstudentInfo(clsStudent& Student)
	{
		cout << "\n\t\t\t\t==========================================================";
		cout << "\n\t\t\t\tID        : " << Student.getID();
		cout << "\n\t\t\t\tFull name : " << Student.fullname();
		cout << "\n\t\t\t\tEmail     : " << Student.getemail();
		cout << "\n\t\t\t\tPhone     : " << Student.getphone();
		cout << "\n\t\t\t\tPassword  : " << Student.getPassword();
		cout << "\n\t\t\t\tPhase     : " << Student.getPhase();
		cout << "\n\t\t\t\t==========================================================\n\n";
	}

public:

	static void ShowDeleteStudentscreen()
	{
		clsScreen::_Drawscreenheader("Delete Student");

		cout << "\nEnter student ID : ";
		string id = clsInputValidate::readstring();

		if (clsStudent::isStudentExist(id))
		{
			clsStudent Student = clsStudent::Find(id);
			_PrintstudentInfo(Student);

			char c;
			cout << "\nAre you sure you want to delete this student ? ( Y/N ) : ";
			cin >> c;

			if (toupper(c) == 'Y')
			{
			    Student.Delete();
				cout << "\nStudent deleted succesfully :-)\n";
			}

		}

		else
		{
			cout << "\nStudent not exist :-(\n";
		}
	}
};

