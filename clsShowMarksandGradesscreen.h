#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMarksandGrades.h"
using namespace std;

class clsShowMarksandGradesscreen : protected clsScreen
{
private:

	static void _Printmarks_grades(clsMarksandGrades &Student)
	{
		cout << "\n\t\t\t\t==========================================================";
		cout << "\n\t\t\t\tMaths        : " << Student.getMaths() << " / " << clsMarksandGrades::STGrade(Student.getMaths());
		cout << "\n\t\t\t\tStatics      : " << Student.getStatics() << " / " << clsMarksandGrades::STGrade(Student.getStatics());
		cout << "\n\t\t\t\tProgramming  : " << Student.getProgramming() << " / " << clsMarksandGrades::STGrade(Student.getProgramming());
		cout << "\n\t\t\t\tPhysics      : " << Student.getPhysics() << " / " << clsMarksandGrades::STGrade(Student.getPhysics());
		cout << "\n\t\t\t\tAverage      : " << Student.getAverage() << " / " << clsMarksandGrades::STGrade(Student.getAverage());
		cout << "\n\t\t\t\tGrade        : " << Student.getGrade();
		cout << "\n\t\t\t\t==========================================================\n\n";
	}

public:

	static void ShowMarksandGradesscreen()
	{
		clsScreen::_Drawscreenheader("Marks and Grades Screen");

		_Printmarks_grades(CurrentStudentMandG);
	}
};