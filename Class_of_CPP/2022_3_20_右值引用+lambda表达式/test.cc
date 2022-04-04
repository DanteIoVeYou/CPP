#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::move;
#include <string>
using std::string;


void Func() {
	cout << endl;
}

template<class T, class ...Args>
void Func(T x, Args... args) {
	
	cout << x << " ";
	Func(args...);
}	


void F() {
	cout << "xauasnkdkasd" << endl;
}

template<class T>
struct cmp {
	bool operator()(T x, T y) {
		return x > y;
	}
};
//int main()
//{

	//Func(1,2,"hello", 3.14);


	//std:: vector<int> v;
	//v.emplace_back(1);
	//v.emplace_back(1);
	//v.emplace_back(1);


	//for (auto e : v) {
	//	cout << e << " ";
	//}
	//cout << endl;
	//void (*pf)() = F;
	//cout << typeid(pf).name() << endl;
	//pf();



	//const int& q  = 10;
	//int&& a = 10;
	//cout << "address: " << &a << " value: " << a << endl;
	//

	//int&& b = move(a);
	//cout << "address: " << &b << " value: " << b << endl;
	//cout << "address: " << &a << " value: " << a << endl;

	//{
	//	static int  aa = 10;
	//}
	//f("hell");

	//int&& a = 10;
	//cout << "address: " << &a << endl;
	//int a = 8888;
	//string b = "hello";
	//::std::vector<::std::string> v;
	//v.push_back(b);
	//v.push_back(b);
	//v.push_back(b);
	//v.push_back(b);
	//v.push_back(move(b));

	//for (auto e : v) {
	//	cout << e << endl;
	//}
	//cout << "b: " << b << endl;
	//int b = 8888;
	//::std::vector<int> v;
	//v.push_back(b);
	//v.push_back(b);
	//v.push_back(b);
	//v.push_back(b);
	//v.push_back(move(b));

	//for (auto e : v) {
	//	cout << e << endl;
	//}
	//cout << "b: " << b << endl;

//	return 0;
//}


struct Item {
	void operator()() {
		cout << "aa" << endl;
	}
	::std::string _name;
	int _price;
	int _comment;
};
int main()
{
	Item i1;
	i1();
	//int x = 10;

	//auto f1 = [] {cout << "I am a lambda" << endl; };
	//auto f2 = [x, f1] {cout << "I am a lambda" << endl; f1(); };
	//f2();

	//cout << typeid(f1).name() << endl;
	//cout << typeid(f2).name() << endl;

	//f1();

	//int x = 1;
	//int y = 2;
	//cout << x << " " << y << endl;
	//auto f3 = [&x, &y]()mutable {int tmp = x; x = y; y = tmp; };
	//f3();
	//cout << x << " " << y << endl;
	//f3();
	//cout << x << " " << y << endl;



	//int x = 20;
	//int y = 30;
	//cout << x << " " << y << endl;

	//auto f1 = [x, y]() mutable{int tmp = x; x = y; y = tmp; };
	//f1();
	//cout << x << " " << y << endl;



	auto f1 = [] {cout << "I am a lambda" << endl; };
	f1();
	return 0;
}