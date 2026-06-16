#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsStudent.h"
#include "clsDoctor.h"
#include "clsMarksandGrades.h"
using namespace std;

class clsShowAddNewStudentscreen : protected clsScreen
{
private:

	static void _ReadStudentInfo(clsStudent& Student, clsMarksandGrades &Marks)
	{
		string title = "Wrong, please enter a number between 0 to 100 : ";

		cout << "\nEnter first name : ";
		Student.setfirstname(clsInputValidate::readstring());

		cout << "\nEnter last name : ";
		Student.setlastname(clsInputValidate::readstring());

		cout << "\nEnter E-mail : ";
		Student.setemail(clsInputValidate::readstring());

		cout << "\nEnter phone : ";
		Student.setphone(clsInputValidate::readstring());

		cout << "\nEnter phone : ";
		Student.setphone(clsInputValidate::readstring());

		cout << "\nEnter password : ";
		Student.setPassword(clsInputValidate::readstring());

		cout << "\nEnter maths mark : ";
		Marks.setMaths(clsInputValidate::ReadNumberBetween<float>(0, 100, title));

		cout << "\nEnter statics mark : ";
		Marks.setStatics(clsInputValidate::ReadNumberBetween<float>(0, 100, title));

		cout << "\nEnter physics mark : ";
		Marks.setPhysics(clsInputValidate::ReadNumberBetween<float>(0, 100, title));

		cout << "\nEnter programming mark : ";
		Marks.setProgramming(clsInputValidate::ReadNumberBetween<float>(0, 100, title));

		Marks.setAverage();
		Marks.setGrade();
	}

public:

	static void ShowAddNewStudentScreen()
	{
		clsScreen::_Drawscreenheader("Add new Student");

		cout << "\nEnter ID : ";
		string id = clsInputValidate::readstring();

		while (clsStudent::isStudentExist(id))
		{
			cout << "\nExist, enter another : ";
			string id = clsInputValidate::readstring();
		}

		clsStudent Student = clsStudent::Find(id);
		clsMarksandGrades Marks = clsMarksandGrades::Find(id);

		_ReadStudentInfo(Student, Marks);

		Student.Addnew();
		Marks.Addnew();

		cout << "\nStudent added succesfully :-)\n";
	}
};