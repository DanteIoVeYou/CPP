#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month) const
	{
		assert(_month > 0 && _month < 13);//判断月份是否非法
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//放在静态区，无需每次都创建一个数组了
		//判断闰年
		int ret = arr[month];
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			ret++;
		}
		return ret;
	}
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// 析构函数
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}

	void Print() const
	{
		if (_year < 0 || _month>12 || _month < 1 || _day < 1 || _day > GetMonthDay(_year, _month))
			cout << _year << "/" << _month << "/" << _day << "->非法日期" << endl;
		else
			cout << _year << "/" << _month << "/" << _day<< endl;

	}

	// 日期+=天数
	Date& operator+=(int day);

	// 日期+天数
	Date operator+(int day);

	// 日期-天数
	Date operator-(int day);

	// 日期-=天数
	Date& operator-=(int day);

	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);

	// 后置--
	Date operator--(int);

	// 前置--
	Date& operator--();

	// >运算符重载
	bool operator>(const Date& d);

	// ==运算符重载
	bool operator==(const Date& d);

	// >=运算符重载
	bool operator >= (const Date& d);

	// <运算符重载
	bool operator < (const Date& d);

	// <=运算符重载
	bool operator <= (const Date& d);

	// !=运算符重载
	bool operator != (const Date& d);

	// 日期-日期 返回天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};