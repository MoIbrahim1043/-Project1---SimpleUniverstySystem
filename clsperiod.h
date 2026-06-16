#pragma once
#include <iostream>
#include "clsdate.h";
using namespace std;

class clsperiod
{
private:
	clsdate startdate;
	clsdate enddate;

public:
	clsperiod(clsdate date1, clsdate date2)
	{
		startdate = date1;
		enddate = date2;
	}

	void setStartdate(clsdate date1)
	{
		startdate = date1;
	}

	void setEnddate(clsdate date2)
	{
		enddate = date2;
	}

	clsdate getStartdate()
	{
		return startdate;
	}

	clsdate getEnddate()
	{
		return enddate;
	}

	static bool isdateinperiod(clsdate date, clsperiod period)
	{
		if (clsdate::isdate1equalsdate2(date, period.startdate) || clsdate::isdate1equalsdate2(date, period.enddate))
		{
			return true;
		}

		else if (clsdate::isdate1afterdate2(date, period.startdate) && clsdate::isdate1lessthandate2(date, period.enddate))
		{
			return true;
		}

		return false;
	}

	bool isdateinperiod(clsdate date)
	{
		return isdateinperiod(date, *this);
	}

	static bool isoverlapperiods(clsperiod period1, clsperiod period2)
	{
		while (!clsdate::isdate1afterdate2(period1.startdate, period1.enddate))
		{
			if (isdateinperiod(period1.startdate, period2))
			{
				return true;
			}

			period1.startdate = clsdate::increasedatebyoneday(period1.startdate);
		}

		return false;
	}

	static short periodlength(clsperiod period, bool includeendday = false)
	{
		return (clsdate::differentdays(period.startdate, period.enddate, includeendday));
	}

	short periodlength(bool includeendday = false)
	{
		return periodlength(*this, includeendday);
	}

	static short overlapdays(clsperiod period1, clsperiod period2)
	{
		short days = 0;

		while (!clsdate::isdate1afterdate2(period1.startdate, period1.enddate))
		{
			if (isdateinperiod(period1.startdate, period2))
			{
				days++;
			}

			period1.startdate = clsdate::increasedatebyoneday(period1.startdate);
		}

		return days;
	}

	void print()
	{
		cout << clsdate::date(startdate) << endl;
		cout << clsdate::date(enddate) << endl;
	}
};