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
	cout << "ÇëÊäÈë:>";
	cin >> d1;
	cout << d1 << endl;
}

int main() {

	Test5();
	return 0;
}


