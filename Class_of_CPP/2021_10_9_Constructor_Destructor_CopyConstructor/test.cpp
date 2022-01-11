#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date {
public:
	void Print() {
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	Date() {
		_year = 1;
		_month = 2;
		_day = 1;
		cout << "Date()" << endl;
	}
	Date(int year , int month , int day = 11) {
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int year, int month, int day)" << endl;
	}
	~Date() {
		_year = 0;
		_month = 0;
		_day = 0;
		cout << "~Date" << endl;
	}

	Date(const Date& date) { //const 避免写反：data._year = _year  --> 引用传参不作输出型参数，最好const &
		_year = date._year;
		_month = date._month;
		_day = date._day;
		cout << "Date copy" << endl;
	}
private:
	int _year;
	int _month;
	int _day ; 
};
int main() {
	Date d;
	Date d1(2022, 1);
	d1.Print();
	Date d2(d);
	Date d3 = d2;
	return 0;
}