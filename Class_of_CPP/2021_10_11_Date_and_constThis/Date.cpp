#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

Date& Date::operator=(const Date& date) {
	if (this != &date) {
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}
	return *this;
}
Date& Date::operator+=(int day) {
	_day += day;
	while (_day > GetDay(_year, _month)) {
		_day -= GetDay(_year, _month);
		_month++;
		if (_month == 13) {
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day) {
	Date tmp(*this);
	tmp += day;
	return tmp;
}
// -=
// method 1
//Date& Date::operator-=(int day) {
//	while (_day < day) {
//		day -= _day;
//		_month--;
//		if (_month == 0) {
//			_year--;
//			_month = 12;
//		}
//		_day = GetDay(_year, _month);
//	}
//	_day -= day;
//	return *this;
//}

// method 2
//Date& Date::operator-=(int day) {
//	if (day > _day) {
//		day -= _day;
//		_month--;
//		if (_month == 0) {
//			_month = 12;
//			_year--;
//		}
//	}
//	while (day > GetDay(_year, _month)) {
//		day -= GetDay(_year, _month);
//		_month--;
//		if (_month == 0) {
//			_month = 12;
//			_year--;
//		}
//	}
//	_day = GetDay(_year, _month) - day;
//	return *this;
//}

// best method
Date& Date::operator-=(int day) {
	_day -= day;

	while (_day <= 0) {
		_month--;
		if (_month == 0) {
			_year--;
			_month = 12;
		}
		_day += GetDay(_year, _month);
	}
	return *this;
}
// -
Date Date::operator-(int day) {
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

// 前置++
Date& Date::operator++() {
	*this += 1;
	return *this;
}
// 后置++
Date Date::operator++(int) {
	Date tmp = *this;
	*this += 1;
	return tmp;
}
// 前置--
Date& Date::operator--() {
	*this -= 1;
	return *this;
}
// 后置--
Date Date::operator--(int) {
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

// ==
bool Date::operator==(const Date& d) {
	return _year == d._year && _month == d._month && _day == d._month;
}
// >
bool Date::operator>(const Date& d) {
	if (_year > d._year) {
		return true;
	}
	else if (_year == d._year && _month > d._month) {
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day) {
		return true;
	}
	else {
		return false;
	}
}
// <
bool Date::operator<(const Date& d) {
	return !(*this > d || *this == d);
}
// >=
bool Date::operator>=(const Date& d) {
	return (*this > d || *this == d);
}
// <=
bool Date::operator<=(const Date& d) {
	return !(*this > d);
}
// !=
bool Date::operator!=(const Date& d) {
	return !(*this == d);
}

// date minus date -> days intervals
int Date::operator-(const Date& d) {
	int i = 0;
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (max < min) {
		max = d;
		min = *this;
		flag = -1;
	}
	while (max > min) {
		min++;
		i++;
	}
	return i * flag;
}

// 流提取
ostream& operator<<(ostream& out, const Date& d) {
	out << d._year << "/" << d._month << "/" << d._day;
	return out;
}
// 流插入
istream& operator>>(istream& in, Date& d) {
	in >> d._year;
	in >> d._month;
	in >> d._day;
	return in;
}
