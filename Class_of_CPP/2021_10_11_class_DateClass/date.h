#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month) const
	{
		assert(_month > 0 && _month < 13);//�ж��·��Ƿ�Ƿ�
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//���ھ�̬��������ÿ�ζ�����һ��������
		//�ж�����
		int ret = arr[month];
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			ret++;
		}
		return ret;
	}
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��������
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}

	void Print() const
	{
		if (_year < 0 || _month>12 || _month < 1 || _day < 1 || _day > GetMonthDay(_year, _month))
			cout << _year << "/" << _month << "/" << _day << "->�Ƿ�����" << endl;
		else
			cout << _year << "/" << _month << "/" << _day<< endl;

	}

	// ����+=����
	Date& operator+=(int day);

	// ����+����
	Date operator+(int day);

	// ����-����
	Date operator-(int day);

	// ����-=����
	Date& operator-=(int day);

	// ǰ��++
	Date& operator++();

	// ����++
	Date operator++(int);

	// ����--
	Date operator--(int);

	// ǰ��--
	Date& operator--();

	// >���������
	bool operator>(const Date& d);

	// ==���������
	bool operator==(const Date& d);

	// >=���������
	bool operator >= (const Date& d);

	// <���������
	bool operator < (const Date& d);

	// <=���������
	bool operator <= (const Date& d);

	// !=���������
	bool operator != (const Date& d);

	// ����-���� ��������
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};