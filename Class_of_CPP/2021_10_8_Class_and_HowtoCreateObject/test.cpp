//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
////class Stack {
////public:
////	Stack()
////	{
////		;
////	}
////	void Init()
////	{
////
////	}
////	void Push(int x)
////	{
////
////	}
////	Stack(Stack& st)
////	{
////			
////	}
////private:
////	int* a;
////	int size;
////	int capacity;
////};
////
////int main()
////{ 
////	Stack st;
////	Stack st2(st);
////	return 0;
////}
//
//class Date {
//public:
//	bool operator<(const Date& x)
//	{
//		if (_year < x._year)
//		{
//			return true;
//		}
//		else if (_year == x._year && _month < x._month)
//		{
//			return true;
//		}
//		else if(_year == x._year && _month == x._month && _day < x._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date& Date::operator+=(int day)
//	{
//		*this = *this + day;
//		return *this;
//
//	}
//	Date& Date::operator-=(int day)
//	{
//		_day -= day;
//		while (_day<=0)
//		{
//			//_day += GetMonthDay(_month);  借上个月的天数，所以不能写这边
//			--_month;
//			if (_month == 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetMonthDay(_month);
//		}
//		return *this;
//	}
//	Date operator--()
//	{
//
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2009, 11, 11);
//	Date d2(2021, 10, 12);
//	//cout << d1 < d2 << endl;
//	printf("%d\n", d1 < d2);
//	return 0;
//}

#include <iostream>
using namespace std;

//
//int main() {
//	int* p = NULL;
//	*p = 1;
//	cout << *p << endl;
//	return 0;
//}


class A {
public:
	void Print() {
		cout << "Print()" << endl;
	}
private:
	int _age;
	char _name[20];
};


int main() {
	A* p = nullptr;
	p->Print();
	return 0;
}