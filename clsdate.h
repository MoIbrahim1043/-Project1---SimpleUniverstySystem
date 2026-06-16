#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include "clsString.h";
#include <vector>
#include <ctime>
using namespace std;

class clsdate
{
private:
	short day;
	short month;
	short year;

public:
	clsdate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		day = now->tm_mday;
		month = now->tm_mon + 1;
		year = now->tm_year + 1900;
	}

	clsdate stringtodate(string stringdate)
	{
		clsdate date;
		vector <string> vdate;
		vdate = clsString::splitstring(stringdate, "/");

		date.day = stoi(vdate.at(0));
		date.month = stoi(vdate.at(1));
		date.year = stoi(vdate.at(2));

		return date;
	}

	clsdate convertdaystodate(short days, short year)
	{
		clsdate date;
		date.month = 1, date.day = 0, date.year = year;

		for (short i = 1; days > daysinmonth(year, i); i++)
		{
			date.month++;
			days -= daysinmonth(year, i);
		}

		date.day = days;

		return date;
	}

	clsdate(string date)
	{
		*this = stringtodate(date);
	}

	clsdate(short Day, short Month, short Year)
	{
		day = Day;
		month = Month;
		year = Year;
	}

	clsdate(short days, short Year)
	{
		*this = convertdaystodate(days, Year);
	}

	static string DateandTime()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		return date(clsdate()) + " - " + to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
	}

	void setday(short day)
	{
		this->day = day;
	}

	short getday()
	{
		return day;
	}

	void setmonth(short month)
	{
		this->month = month;
	}

	short getmonth()
	{
		return month;
	}

	void setyear(short year)
	{
		this->year = year;
	}

	short getyear()
	{
		return year;
	}

	static bool isleapyear(short year)
	{
		return (year % 400 == 0) ? true : (year % 4 == 0 && year % 100 != 0) ? true : false;
	}

	short daysinyear(short year)
	{
		return (isleapyear(year)) ? 366 : 365;
	}

	short hoursinyear(short year)
	{
		return daysinyear(year) * 24;
	}

	int minutesinyear(short year)
	{
		return hoursinyear(year) * 60;
	}

	unsigned int secondsinyear(short year)
	{
		return minutesinyear(year) * 60;
	}

	static short daysinmonth(short year, short month)
	{
		short days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (month > 12 || month < 1) ? 0 : (month == 2) ? ((isleapyear(year)) ? 29 : 28) : days[month - 1];
	}

	short hoursinmonth(short year, short month)
	{
		return daysinmonth(year, month) * 24;
	}

	unsigned short minutesinmonth(short year, short month)
	{
		return hoursinmonth(year, month) * 60;
	}

	int secondsinmonth(short year, short month)
	{
		return minutesinmonth(year, month) * 60;
	}

	static short Dayorder(short year, short month, short day)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	static string date(clsdate date)
	{
		return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
	}

	static string dayname(short dayorder)
	{
		string days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return days[dayorder];
	}

	static string monthname(short month)
	{
		string months[12] = { "Jan", "Feb", "Mar", "Apr" , "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return months[month - 1];
	}

	static void printmonthcalendar(short year, short month)
	{
		short dayorder = Dayorder(year, month, 1);
		short days = daysinmonth(year, month);
		cout << "\n  ___________________" << monthname(month) << "___________________\n  ";

		for (short i = 0; i <= 6; i++)
		{
			cout << dayname(i) << "  ";
		}

		cout << endl;
		short i;
		for (i = 0; i < dayorder; i++)
		{
			cout << "     ";
		}

		for (short j = 1; j <= days; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				cout << endl;
				i = 0;
			}
		}

		cout << "\n  _____________________________________________________________\n";
	}

	void printmonthcalendar()
	{
		printmonthcalendar(this->year, this->month);
	}

	static void printyearcalendar(short year)
	{
		cout << "____________________________________________________\n\n";
		cout << "            Calendar - " << year << endl;
		cout << "____________________________________________________\n";

		for (short i = 0; i < 11; i++)
		{
			printmonthcalendar(year, i + 1);
		}
	}

	void printyearcalendar()
	{
		printyearcalendar(year);
	}

	short daysfromyearbegin(short year, short month, short day)
	{
		short days = 0;

		for (short i = 1; i < month; i++)
		{
			days += daysinmonth(year, i);
		}

		days += day;

		return days;
	}

	clsdate adddaystodate(short days, clsdate date)
	{
		days = days + date.day;

		while (days > daysinmonth(date.year, date.month))
		{
			days = days - (daysinmonth(date.year, date.month));

			date.month++;
			if (date.month == 13)
			{
				date.month = 1;
				date.year++;
			}
		}

		date.day = days;

		return date;
	}

	static bool isdate1lessthandate2(clsdate date1, clsdate  date2)
	{
		return (date1.year > date2.year) ? false : (date1.year < date2.year) ? true
			: (date1.month > date2.month) ? false : (date1.month < date2.month) ? true
			: (date1.day < date2.day) ? true : false;
	}

	bool isdatelessthandate2(clsdate  date2)
	{
		return isdate1lessthandate2(*this, date2);
	}

	static bool isdate1equalsdate2(clsdate date1, clsdate date2)
	{
		return (date1.year != date2.year) ? false : (date1.month != date2.month) ? false : (date1.day == date2.day) ? true : false;
	}

	bool isdateequalsdate2(clsdate date2)
	{
		return isdate1equalsdate2(*this, date2);
	}

	static bool islastdayinmonth(clsdate date)
	{
		return (date.day == daysinmonth(date.year, date.month));
	}

	static bool islastmonthinyear(short month)
	{
		return (month == 12);
	}

	static clsdate increasedatebyoneday(clsdate& date)
	{
		if (islastdayinmonth(date))
		{
			date.day = 1;

			if (islastmonthinyear(date.month))
			{
				date.year++;
				date.month = 1;
			}

			else
			{
				date.month++;
			}
		}

		else
			date.day++;

		return date;
	}

	void increasedatebyoneday()
	{
		*this = increasedatebyoneday(*this);
	}

	static short differentdays(clsdate date1, clsdate date2, bool includeendday = false)
	{
		short diff = 0;

		while (isdate1lessthandate2(date1, date2))
		{
			date1 = increasedatebyoneday(date1);
			diff++;
		}

		while (isdate1lessthandate2(date2, date1))
		{
			date2 = increasedatebyoneday(date2);
			diff--;
		}

		return (includeendday) ? ((diff < 0) ? (diff - 1) : (diff + 1)) : diff;
	}

	short differentdays(clsdate date2, bool includeendday = false)
	{
		return differentdays(*this, date2, includeendday);
	}

	static clsdate increasedatebyxdays(clsdate& date, short x)
	{
		for (short i = 0; i < x; i++)
		{
			date = increasedatebyoneday(date);
		}

		return date;
	}

	void increasedatebyxdays(short x)
	{
		increasedatebyxdays(*this, x);
	}

	static clsdate increasedatebyoneweek(clsdate& date)
	{
		return (increasedatebyxdays(date, 7));
	}

	void increasedatebyoneweek()
	{
		increasedatebyoneweek(*this);
	}

	static clsdate increasedatebyxweeks(clsdate& date, short x)
	{
		for (short i = 0; i < x; i++)
		{
			date = increasedatebyoneweek(date);
		}

		return date;
	}

	void increasedatebyxweeks(short x)
	{
		increasedatebyxweeks(*this, x);
	}

	static clsdate increasedatebyonemonth(clsdate& date)
	{
		if (date.month == 12)
		{
			date.month = 1;
			date.year++;
		}

		else
			date.month++;

		if (date.day > daysinmonth(date.year, date.month))
			date.day = daysinmonth(date.year, date.month);

		return date;
	}

	void increasedatebyonemonth()
	{
		increasedatebyonemonth(*this);
	}

	static clsdate increasedatebyxmonths(clsdate& date, short x)
	{
		for (short i = 0; i < x; i++)
		{
			date = increasedatebyonemonth(date);
		}

		return date;
	}

	void increasedatebyxmonths(short x)
	{
		increasedatebyxmonths(*this, x);
	}

	static clsdate increasedatebyoneyear(clsdate& date)
	{
		date.year++;

		if (date.day > daysinmonth(date.year, date.month))
			date.day = daysinmonth(date.year, date.month);

		return date;
	}

	void increasedatebyoneyear()
	{
		increasedatebyoneyear(*this);
	}

	static clsdate increasedatebyxyears(clsdate& date, short x)
	{
		date.year += x;

		return date;
	}

	void increasedatebyxyears(short x)
	{
		increasedatebyxyears(*this, x);
	}

	static clsdate increasedatebyonedecade(clsdate& date)
	{
		date.year += 10;

		if (date.day > daysinmonth(date.year, date.month))
			date.day = daysinmonth(date.year, date.month);

		return date;
	}

	void increasedatebyonedecade()
	{
		increasedatebyonedecade(*this);
	}

	static clsdate increasedatebyxdecades(clsdate& date, short x)
	{
		date.year += (10 * x);
		return date;
	}

	void increasedatebyxdecades(short x)
	{
		increasedatebyxdecades(*this, x);
	}

	static clsdate increasedatebyonecentury(clsdate& date)
	{
		date.year += 100;
		return date;
	}

	void increasedatebyonecentury()
	{
		increasedatebyonecentury(*this);
	}

	static clsdate increasedatebyonemillennium(clsdate& date)
	{
		date.year += 1000;
		return date;
	}

	void increasedatebyonemillennium()
	{
		increasedatebyonemillennium(*this);
	}

	static clsdate decreasedatebyoneday(clsdate& date)
	{
		if (date.day == 1)
		{
			if (date.month == 1)
			{
				date.month = 12;
				date.year--;
			}

			else
			{
				date.month--;
			}

			date.day = daysinmonth(date.year, date.month);
		}

		else
		{
			date.day--;
		}

		return date;
	}

	void decreasedatebyoneday()
	{
		decreasedatebyoneday(*this);
	}

	static clsdate decreasedatebyxdays(clsdate& date, short x)
	{
		for (short i = 0; i < x; i++)
		{
			date = decreasedatebyoneday(date);
		}

		return date;
	}

	void decreasedatebyxdays(short x)
	{
		decreasedatebyxdays(*this, x);
	}

	static clsdate decreasedatebyoneweek(clsdate& date)
	{
		return (decreasedatebyxdays(date, 7));
	}

	void decreasedatebyoneweek()
	{
		decreasedatebyoneweek(*this);
	}

	static clsdate decreasedatebyxweeks(clsdate& date, short x)
	{
		for (short i = 0; i < x; i++)
		{
			date = decreasedatebyoneweek(date);
		}

		return date;
	}

	void decreasedatebyxweeks(short x)
	{
		decreasedatebyxweeks(*this, x);
	}

	static clsdate decreasedatebyonemonth(clsdate& date)
	{
		if (date.month == 1)
		{
			date.month = 12;
			date.year--;
		}

		else
			date.month--;

		if (date.day > daysinmonth(date.year, date.month))
			date.day = daysinmonth(date.year, date.month);

		return date;
	}

	void decreasedatebyonemonth()
	{
		decreasedatebyonemonth(*this);
	}

	static clsdate decreasedatebyxmonths(clsdate& date, short x)
	{
		for (short i = 0; i < x; i++)
		{
			date = decreasedatebyonemonth(date);
		}

		return date;
	}

	void decreasedatebyxmonths(short x)
	{
		decreasedatebyxmonths(*this, x);
	}

	static clsdate decreasedatebyoneyear(clsdate& date)
	{
		date.year--;

		if (date.day > daysinmonth(date.year, date.month))
			date.day = daysinmonth(date.year, date.month);

		return date;
	}

	void decreasedatebyoneyear()
	{
		decreasedatebyoneyear(*this);
	}

	static clsdate decreasedatebyxyears(clsdate& date, short x)
	{
		date.year -= x;
		return date;
	}

	void decreasedatebyxyears(short x)
	{
		decreasedatebyxyears(*this, x);
	}

	static clsdate decreasedatebyonedecade(clsdate& date)
	{
		date.year -= 10;
		return date;
	}

	void decreasedatebyonedecade()
	{
		decreasedatebyonedecade(*this);
	}

	static clsdate decreasedatebyxdecades(clsdate& date, short x)
	{
		date.year -= (x * 10);
		return date;
	}

	void decreasedatebyxdecades(short x)
	{
		decreasedatebyxdecades(*this, x);
	}

	static clsdate decreasedatebyonecentury(clsdate& date)
	{
		date.year -= 100;
		return date;
	}

	void decreasedatebyonecentury()
	{
		decreasedatebyonecentury(*this);
	}

	static clsdate decreasedatebyonemillenium(clsdate& date)
	{
		date.year -= 1000;
		return date;
	}

	void decreasedatebyonemillenium()
	{
		decreasedatebyonemillenium(*this);
	}

	static bool isendofweek(clsdate date)
	{
		return (clsdate::Dayorder(date.year, date.month, date.day) == 6);
	}

	bool isendofweek()
	{
		return isendofweek(*this);
	}

	static bool isweekend(clsdate date)
	{
		short dayorder = Dayorder(date.year, date.month, date.day);
		return (dayorder == 5 || dayorder == 6);
	}

	bool isweekend()
	{
		return isweekend(*this);
	}

	static short daysuntilendofweek(clsdate date)
	{
		return (6 - Dayorder(date.year, date.month, date.day));
	}

	short daysuntilendofweek()
	{
		return daysuntilendofweek(*this);
	}

	static short daysuntilendofmonth(clsdate date)
	{
		return (daysinmonth(date.year, date.month) - date.day) + 1;
	}

	short daysuntilendofmonth()
	{
		return daysuntilendofmonth(*this);
	}

	static short daysuntilendofyear(clsdate date)
	{
		short days = 0;

		while (!(islastdayinmonth(date) && islastmonthinyear(date.month)))
		{
			date = increasedatebyoneday(date);
			days++;
		}

		days++;
		return days;
	}

	short daysuntilendofyear()
	{
		return daysuntilendofyear(*this);
	}

	static bool isdate1afterdate2(clsdate date1, clsdate date2)
	{
		return (!isdate1equalsdate2(date1, date2) && !isdate1lessthandate2(date1, date2));
	}

	bool isdateafterdate2(clsdate date2)
	{
		return isdate1afterdate2(*this, date2);
	}

	static bool isvalid(clsdate date)
	{
		return (date.day > daysinmonth(date.year, date.month) || date.day < 1) ? false : (date.month > 12 || date.month < 1) ? false : true;
	}

	bool isvalid()
	{
		return isvalid(*this);
	}

	static void  SwapDates(clsdate& Date1, clsdate& Date2)
	{

		clsdate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	void print()
	{
		cout << date(*this) << endl;
	}

	__declspec(property(get = getday, put = setday)) short day;
	__declspec(property(get = getmonth, put = setmonth)) short month;
	__declspec(property(get = getyear, put = setyear)) short year;
};