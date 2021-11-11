#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
T Add(T a, T b)
{
	return a + b;
}

//普通类，类名就是类型
//对于类模板，类名不是类型，是Stack<T>，要加一个模板参数
template<class T>
class Stack
{
public:
	Stack(int _capacity = 4)
		:_a(new T[_capacity])
		,_top(0)
		,_capacity(_capacity)
	{}
	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_top = _capacity = 0;
	}
	void Push(const T& x);
private:
	T* _a;
	int _top;
	int _capacity;
};


//模板不支持把声明写到.h，定义写到.cpp这种声明和定义分离的写法，会报链接错误。不能在两个文件
//定义在类外面
template<class T>
void Stack<T>::Push(const T& x)
{
	
}

//int main()
//{
//	double c = 1.1, d = 1.2;
//	Swap(c, d);
//	int a = 0, b = 1;
//	cout << a << " " << b << endl;
//	10;
//	30;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	Add<int>(1, 2);
//	return 0;
//}


//PJ版本
//SGI版本（源码学习看这个）	
//vector增容 vs 1.5倍增容，g++ 2倍增容
/*
STL六大

容器
算法
迭代器
仿函数
空间配置器
配接器 
*/

#include <string>//basic_string是一个模板；char顺序表
//int main()
//{
//	string s1("hello world");
//	string s2("陕西");
//
//	cout << sizeof(char) << endl;
//	cout << sizeof(wchar_t) << endl;
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s2 << endl;
//
//	//遍历方式
//	// 1.for
//  // string重载了operator[]
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		s1[i] += 1;
//	}
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << " " << endl;
//	}
//	// 2.迭代器
//	// 3.范围for
//	for (auto& o : s1)
//	{
//		o--;
//	}
//	for (auto o : s1)
//	{
//		cout << o << endl;
//	}
//	return 0;
//}

int main()
{
	string s1("hello ");
	s1.push_back('w');
	s1.append("orld");
	s1 += "!!";
	s1 += '!';
	cout << s1 << endl;
	return 0;
}







