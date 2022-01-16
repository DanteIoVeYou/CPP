# 1.前言

阅读本文的预备知识：
- 构造函数、拷贝构造、拷贝构造
- 类访问限定符
- 类的实例化
- this指针
- 引用返回

目录：
- 运算符重载
- 友元函数、友元类、内部类
- 日期类

在我们快速入门了C++以后，首当其冲的便是学习C++基于面向对象的特性。

我们将事物抽象成一个类，再通过 “类” 这张`图纸`实例化出一个个具体的对象，在封装的特点下管理对象的数据与方法



# 2.运算符重载

我们的加减乘除等`算术运算符`和> < ==等`关系运算符`以及 = `赋值运算符`天然能够操作int、float等`内置类型数据`；但是对于自定义类型的数据，比如说我们的类，由于类之间的运算、比较等操作会根据具体一个类的属性的变化而变化，所以运算符的默认用法已经满足不了我们的需求了

于是，我们需要自定义运算符在类层面上的用法，就有了`运算符重载`

我们是这样重载一个运算符的：
```cpp
返回值 operator运算符(参数){
	// 实现
}
```

**注意：**
- 重载之后的运算符的用法、参数位于运算符左右的位置应与常见用法一致
- 第一个参数是默认没写的this指针
- 运算符重载可以在类里面声明和定义，但是这样做的话第一个参数就一定是this指针了；[我们在重载`流插入<<、流提取>>`时需要注意](#anchor)
- 运算符还能在类外面重载，但是这样的话如果想访问私有成员变量，需要定义`友元函数`或是定义一个公有函数拿到私有成员变量；我们在重载`流插入<<、流提取>>`时需要注意
- 声明定义分离，定义的时候用加域操作符`::`

```cpp
Date& Date::operator+=(int day) {
	// 实现
}
```
- 有五个操作符不能重载
  - .*
  - ?:
  - ::
  - sizeof
  - .

# 3.友元
## 3.1友元函数
全局函数不在类内部，无法访问私有成员函数，怎么办？

>我有一个朋友

>`我`要访问**你**，在你内部声明：`我`是**你**的友元


>友元函数可以直接访问类的私有成员，它是定义在类外部的普通函数，不属于任何类，但需要在类的内部声明，声明时需要加`friend关键字`。

这样就把全局函数变成了一个类的友元，该函数可肆无忌惮访问类的私有成员变量了

```cpp
friend ostream& operator<<(ostream& out, const Date& d);
friend istream& operator>>(istream& in, Date& d);
```
说明：
- 友元函数可访问类的私有和保护成员，但`不是类的成员函数`
- 友元函数`不能用const修饰`
- 友元函数可以`在类定义的任何地方声明`，不受类访问限定符限制，我喜欢写在类的开头
- 一个函数可以是多个类的友元函数
- 友元函数的调用与普通函数的调用和原理相同
## 3.2友元类
那么友元类，就是一个类能肆无忌惮访问其他类的私有成员变量
注意：
- 友元关系是单向的，不具有交换性：`你把我当朋友，我不一定把你当朋友`
>比如上述Time类和Date类，在Time类中声明Date类为其友元类，那么可以在Date类中直接访问Time
类的私有成员变量，但想在Time类中访问Date类中私有的成员变量则不行。
- 友元关系不能传递
>如果B是A的友元，C是B的友元，则不能说明C时A的友元。
```cpp
friend class Date;
```
## 3.3内部类
至于`内部类`，即类里面再定义一个类；此时这个内部类是一个独立的类，`它不属于外部类`，**更不能通过
外部类的对象去调用内部类**

内部类就是外部类的友元类。注意友元类的定义，内部类可以通过外部类的对象参数来访问外部类中
的所有成员。但是外部类不是内部类的友元。
注意：
1. 内部类可以定义在外部类的public、protected、private都是可以的。
2. 注意内部类可以直接访问外部类中的static、枚举成员，不需要外部类的对象/类名。
3. sizeof(外部类)=外部类，和内部类没有任何关系。

```cpp
class A {
private:
	static int k;
	int h;
public:
	class B {
	public:
		void foo(const A& a) {
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
	};
};
int A::k = 1;
int main() {
	A::B b;
	b.foo(A());
	return 0;
}
```
# 4.日期类
>Date.h

```cpp
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
```

>Date.cpp

```cpp
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

	// 流插入
	ostream& operator<<(ostream& out, const Date& d) {
		out << d._year << "/" << d._month << "/" << d._day;
		return out;
	}
	 //流提取
	istream& operator>>(istream& in, Date& d) {
		in >> d._year;
		in >> d._month;
		in >> d._day;
		return in;
	}
```
<a id="anchor">流插入、流提取👆👆👆看上面最后两段代码，和Date.h开头的友元函数声明</a>
>test.cpp

```cpp
#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

void Print(const Date& d) {
	cout << d._year << "/" << d._month << "/" << d._day << endl;
}
void Test1() {
	Date d1(2000, 1, 1);
	d1.Print();
	d1 += 100;
	d1.Print();
	d1 += 500;
	d1.Print();
	d1 -= 500;
	d1.Print();
	d1 -= 100;
	d1.Print();
}

void Test2() {
	Date d1(2000, 1, 1);
	Print(d1);
	Print(d1++);
	Print(d1);
	Print(++d1);
	Print(d1);
	Print(d1--);
	Print(d1);
	Print(--d1);
	Print(d1);
}

void Test3() {
	Date d1(2000, 1, 2);
	Date d2(2000, 1, 1);
	cout << "d1==d2: " << (d1 == d2) << endl;
	cout << "d1>d2: " << (d1 > d2) << endl;
	cout << "d1<d2: " << (d1 < d2) << endl;
	cout << "d1>=d2: " << (d1 >= d2) << endl;
	cout << "d1<=d2: " << (d1 <= d2) << endl;
	cout << "d1!=d2: " << (d1 != d2) << endl;
}

void Test4() {
	Date d1(2022, 1, 14);
	Date d2(2022, 2, 20);
	cout << "2022/1/14 - 2022/2/20 = " << d1 - d2 << endl;
	cout << "2022/2/20 - 2022/1/14 = " << d2 - d1 << endl;
}

void Test5() {
	Date d1;
	cout << d1 << endl;
	cout << "请输入:>";
	cin >> d1;
	cout << d1 << endl;
}

int main() {

	Test5();
	return 0;
}
```

