#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//// 人类
//class Person {
//	friend class Student;
//
//public:
//
//
//private:
//	string _name;
//	int _age;
//	string _sex;
//	void P() {
//		cout << "private" << endl;
//	}
//protected:
//	void P2() {
//		cout << "protected" << endl;
//	}
//
//};
//
//// 学生类
//class Student  {
//public:
//	void eat() {
//		cout << "eat beaf" << endl;
//	} 
//	void print(Person pp) {
//		// _age = 10; 父类私有不可见
//		
//	
//		pp._age = 1;
//		p._age = 213;
//	}
//	
//protected:
//	
//private:
//	/*string _name;
//	int _age;
//	string _sex;*/
//	Person p;
//	string _StuID;
//};
//
//// 老师类
//class Teacher :public Person {
//public:
//
//private:
//	string _WorkID;
//};


//int main()
//{
//	Student st;
//	st.eat();
//	cout << sizeof(st) << endl;
//	return 0;
//}


//class Point
//{
//private:
//    double x;
//    double y;
//public:
//    Point(double a, double b)
//    {
//        x = a;
//        y = b;
//    }
//    int GetPoint()
//    {
//        cout << "(" << x << "," << y << ")";
//        return 0;
//    }
//    int distancetoLine()
//    {
//
//    }
//    friend class Tool;
//};
//
//class Tool
//{
//public:
//    double GetX(Point& A)
//    {
//        cout << A.x << endl;
//        return A.x;
//    }
//    double GetY(Point& A)
//    {
//        cout << A.y << endl;
//        return A.y;
//    }
//    double dis(Point& A)
//    {
//        cout << sqrt(A.x * A.x + A.y * A.y) << endl;
//        return  sqrt(A.x * A.x + A.y * A.y);
//    }
//};
//
//int main()
//{
//    Point A(2.0, 3.0);
//    Tool T;
//    T.GetX(A);
//    T.GetY(A);
//    T.dis(A);
//    return 0;
//}

class A {
public:
	void func() {
		cout << "A::func()" << endl;
	}
};

class B: public A {
public:
	void func(int x) {
		cout << "B::func()" << endl;
	}
};
int main() {
	B b;
	b.func();
}