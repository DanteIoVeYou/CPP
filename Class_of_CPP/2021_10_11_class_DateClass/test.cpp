#define _CRT_SECURE_NO_WARNINGS 1
#include "date.h"
void Test3()
{
	Date d0(2019, 10, 24);
	Date d1(2021, 10, 24);
	Date d2(2020, 10, 24);
	Date d3(2022, 10, 24);
	Date d4(d1);
	cout << (d1 >= d3) << endl;
	cout << (d1 <= d3) << endl;

	cout << (d1 == d4) << endl;
	cout << (d1 != d4) << endl;
	cout << (d1 <= d4) << endl;
	cout << (d1 >= d4) << endl;
	cout << (d2 - d1) << endl;
	cout << (d1 - d2) << endl;
	cout << (d1 - d1) << endl;
	cout << (d2 - d0) << endl;



}
void Test2()
{
	Date d1(2021, 10, 24);
	Date d2(d1);
	Date d3(d1);
	d1.Print();
	d1++.Print();
	d2.Print();
	(++d2).Print();
	(d3 + (-1)).Print();
	(d3 - (-1)).Print();

	d3 += -1;
	d3.Print();
	d3 -= -1;
	d3.Print();

}
void Test1()
{
	Date d1(2021, 10, 24);
	Date d2(2021, 10, 32);
	d1.Print();
	d2.Print();
	Date d3(d1);
	d3.Print();
	d1 += 100;
	d1.Print();
	Date d4(d1 + 100);
	d1.Print();
	d4.Print();

	d1.Print();
	d1 += 100;
	d1.Print();
	d1 -= 100;
	d1.Print();
}
int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}