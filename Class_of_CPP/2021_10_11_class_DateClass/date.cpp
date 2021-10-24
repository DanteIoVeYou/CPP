#define _CRT_SECURE_NO_WARNINGS 1
#include "date.h"
// 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
	if (&d == this)
		return *this;
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

// 日期+=天数
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= (-day);
		return *this;
	}
	_day = _day + day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
// 日期+天数
// 复用
Date Date::operator+(int day)
{
	if (day < 0)
	{
		Date tmp(*this);
		tmp -= (-day);
		return tmp;
	}
	Date tmp(*this);
	tmp += day;
	return tmp;
}


// 日期-天数
Date Date::operator-(int day)
{
	if (day < 0)
	{
		Date tmp(*this);
		tmp += (-day);
		return tmp;
	}
	Date tmp(day);
	_day -= day;
	return *this;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += (-day);
		return *this;
	}
	_day -= day;
	while (_day < 0)
	{
		_month--;
		_day += GetMonthDay(_year, _month);
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
	}
	return *this;
}

// 前置++
Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this = *this + 1;
	return tmp;
}

// 后置--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this = *this - 1;
	return tmp;
}

// 前置--
Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;
}

// ==运算符重载
bool Date::operator==(const Date& d)
{
	return (_year == d._year && _month == d._month && _day == d._day);
}

// >=运算符重载
bool Date::operator >= (const Date& d)
{
	return (*this > d || *this == d);
}

// <运算符重载
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	int count = 0;
	int flag = 1;
	Date dbig = *this;
	Date dsmall = d;
	if (*this < d)
	{
		dbig = d;
		dsmall = *this;
		flag = -1;
	}
	while (dsmall++ < dbig)
		count++;
	return flag*count;
}

