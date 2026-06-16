#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
private:
	string _firstname;
	string _lastname;
	string _email;
	string _phone;

public:
	clsPerson(string firstname, string lastname, string email, string phone)
	{
		_firstname = firstname;
		_lastname = lastname;
		_email = email;
		_phone = phone;
	}

	string fullname()
	{
		return _firstname + " " + _lastname;
	}

	void setfirstname(string firstname)
	{
		_firstname = firstname;
	}

	void setlastname(string lastname)
	{
		_lastname = lastname;
	}

	void setemail(string email)
	{
		_email = email;
	}

	void setphone(string phone)
	{
		_phone = phone;
	}

	string getfirstname()
	{
		return _firstname;
	}

	string getlastname()
	{
		return _lastname;
	}

	string getemail()
	{
		return _email;
	}

	string getphone()
	{
		return _phone;
	}
};