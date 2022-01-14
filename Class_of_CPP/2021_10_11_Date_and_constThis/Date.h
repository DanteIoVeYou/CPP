#pragma once
#include <iostream>
using namespace std;

class Date {
	friend void Print(const Date& d);
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
	

public:
	// Get the days of a specific month, using an array to reflect the days 
	int GetDay(int year, int month) {
		static int dayOfmonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
			return 29;
		}
		else {
			return dayOfmonth[month];
		}
		
	}
	// constructor
	Date(int year = 0, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	// destructor
	~Date() {
		_year = 0;
		_month = 1;
		_day = 1;
	}
	// copy constructor
	Date(const Date& tmp) {
		_year = tmp._year;
		_month = tmp._month;
		_day = tmp._day;
	}
	// Print the date
	void Print() {
		if (_year < 0 || _month <= 0 || _month > 12 || _day <= 0 || _day > GetDay(_year, _month)) {
			cout << _year << '/' << _month << '/' << _day << "------illegal date!" << endl;;
		}
		else {
			cout << _year << '/' << _month << '/' << _day << endl;
		}
	}

	// reload functions
	// =
	Date& operator=(const Date& date);
	// 8 assignment
	// +=
	Date& operator+=(int day);
	// +
	Date operator+(int day);
	// -=
	Date& operator-=(int day);
	// -
	Date operator-(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 前置--
	Date& operator--();
	// 后置--
	Date operator--(int);

	// 6 comparable operators
	// ==
	bool operator==(const Date& d);
	// >
	bool operator>(const Date& d);
	// <
	bool operator<(const Date& d);
	// >=
	bool operator>=(const Date& d);
	// <=
	bool operator<=(const Date& d);
	// !=
	bool operator!=(const Date& d);

	// date minus date -> days intervals
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
