#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
using namespace std;

static int s = 99;

template<class T, size_t N>
class Stack {
public:
	T _arr[N];
	int _size;
};
int main()
{

	const int n = 10;
	int arr[n] = { 12 };
	for (auto eL : arr) {
		cout << eL << endl;

	}
	Stack<int, n> st1;
	return 0;
}