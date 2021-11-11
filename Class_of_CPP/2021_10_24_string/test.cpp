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

//��ͨ�࣬������������
//������ģ�壬�����������ͣ���Stack<T>��Ҫ��һ��ģ�����
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


//ģ�岻֧�ְ�����д��.h������д��.cpp���������Ͷ�������д�����ᱨ���Ӵ��󡣲����������ļ�
//������������
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


//PJ�汾
//SGI�汾��Դ��ѧϰ�������	
//vector���� vs 1.5�����ݣ�g++ 2������
/*
STL����

����
�㷨
������
�º���
�ռ�������
����� 
*/

#include <string>//basic_string��һ��ģ�壻char˳���
//int main()
//{
//	string s1("hello world");
//	string s2("����");
//
//	cout << sizeof(char) << endl;
//	cout << sizeof(wchar_t) << endl;
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s2 << endl;
//
//	//������ʽ
//	// 1.for
//  // string������operator[]
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		s1[i] += 1;
//	}
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << " " << endl;
//	}
//	// 2.������
//	// 3.��Χfor
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







