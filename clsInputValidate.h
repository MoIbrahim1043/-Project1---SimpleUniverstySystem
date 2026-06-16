#pragma once
#include <iostream>
#include <string>
#include "clsdate.h";
#include "clsperiod.h";
using namespace std;

class clsInputValidate
{
public:
	static string readstring()
	{
		string s;
		getline(cin >> ws, s);

		return s;
	}

	template <typename DataType> static bool isNumberbetween(DataType number, DataType num1, DataType num2)
	{
		return (number >= num1 && number <= num2) ? true : (number >= num2 && number <= num1) ? true : false;
	}

	static bool isDatebetween(clsdate date, clsdate date1, clsdate date2)
	{
		clsperiod period(date1, date2);

		if (period.isdateinperiod(date))
		{
			return true;
		}

		period.setStartdate(date2);
		period.setEnddate(date1);

		if (period.isdateinperiod(date))
		{
			return true;
		}

		return false;
	}

	template <typename DataType> static DataType ReadNumber(string errormessage = "Invalid case, please enter again : ")
	{
		DataType number;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << errormessage;
			cin >> number;
		}

		return number;
	}

	template <typename DataType> static DataType ReadNumberBetween(DataType num1, DataType num2, string errormessage = "Wrong, please enter a number within range : ")
	{
		DataType number = ReadNumber<DataType>();

		while (!isNumberbetween(number, num1, num2))
		{
			cout << errormessage;
			number = ReadNumber<DataType>();
		}

		return number;
	}

	static bool isValidDate(clsdate date)
	{
		return clsdate::isvalid(date);
	}
};