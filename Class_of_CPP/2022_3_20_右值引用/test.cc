#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::move;
#include <string>
using std::string;
void f(string a) {
	cout << "sdasd" << endl;
}
int main()
{
	const int& q  = 10;
	int&& a = 10;
	cout << "address: " << &a << " value: " << a << endl;
	

	int&& b = move(a);
	cout << "address: " << &b << " value: " << b << endl;
	cout << "address: " << &a << " value: " << a << endl;

	{
		static int  aa = 10;
	}
	f("hell");
	return 0;
}