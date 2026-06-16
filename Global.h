#pragma once
#include "clsStudent.h"
#include "clsDoctor.h"
#include "clsManager.h"
#include "clsMarksandGrades.h"
using namespace std;

clsStudent CurrentStudent = clsStudent::Find("", "");
clsMarksandGrades CurrentStudentMandG = clsMarksandGrades::Find("");
clsDoctor CurrentDoctor = clsDoctor::Find("");
clsManager CurrentManager = clsManager::Find("");
short LoginOption = 0;