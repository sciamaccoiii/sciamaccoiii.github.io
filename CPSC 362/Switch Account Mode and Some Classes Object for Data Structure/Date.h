#include <iostream>
#include <string>
#include <time.h>
#include <map>
#include<vector>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date()
	{
		/*
		time_t rawtime;
		time(&rawtime);
		char  timeNow[26];
		ctime_s(timeNow, sizeof timeNow, &rawtime);
		string conTimeNow = timeNow;
		string monthNow = conTimeNow.substr(4, 3), dayNow = conTimeNow.substr(8, 2), yearNow = conTimeNow.substr(20, 4);
        map<string, int> months
		{
			{ "Jan", 1 },
			{ "Feb", 2 },
			{ "Mar", 3 },
			{ "Apr", 4 },
			{ "May", 5 },
			{ "Jun", 6 },
			{ "Jul", 7 },
			{ "Aug", 8 },
			{ "Sep", 9 },
			{ "Oct", 10 },
			{ "Nov", 11 },
			{ "Dec", 12 }
		};
     const auto iter = months.find(monthNow);
      if (iter != months.cend())
		month = iter->second;

		day = stoi(dayNow, nullptr, 10);
		year = stoi(yearNow, nullptr, 10);*/
		month = 0;
		year = 0;
		day = 0;
	}
	Date(int newMonth, int newDay, int newYear)
	{
		month = newMonth;
		day = newDay;
		year = newYear;
	}

	int getDay()
	{
		return day;
	}

	int getMonth()
	{
		return month;
	}

	int getYear()
	{
		return year;
	}

	void newDay(int newDay)
	{
		day = newDay;
	}

	void newMonth(int newMonth)
	{
		month = newMonth;
	}

	void newYear(int newYear)
	{
		year = newYear;
	}

	Date& operator=(Date& other)
	{
		if (this == &other)
			return *this;
         
		else
		{
			this->newMonth(other.getMonth());
			this->newDay(other.getDay());
			this->newYear(other.getYear());
		}
	}

	string dateFormat()
	{
		string monthF, dayF;

		if (month < 10)
		{
			monthF = "0" + to_string(month);
		}
		if (day < 10)
		{
			dayF = "0" + to_string(day);
		}
		return monthF + "/" + dayF + "/" + to_string(year);
	}
	~Date() {}
};

#endif