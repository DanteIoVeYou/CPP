#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

class Date{
public:
	Date(int year = 0, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
		cout << "Construct success" << endl;
	}
	~Date() {
		_year = 0;
		_month = 1;
		_day = 1;
		cout << "Destruct success" << endl;
	}
	void Print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//private:
//	ListNode* _head;
//};
//int main()
//{
//	List l;
//	return 0
//}
//int main() {
//	int* pa = new int(11);
//	int* paa = new int[5];
//	Date* ptr = new Date(2, 2, 2);
//	ptr->Print();
//	delete(ptr);
//	Date* ptr1 = new Date[5];
//	delete[] ptr1;
//	int* p = (int*)malloc(sizeof(int));
//	free(p);
//	return 0;
//}
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};

void Test1()
{
	// pt现在指向的只不过是与Test对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt) Test; // 注意：如果Test类的构造函数有参数时，此处需要传参
}

int main() {
	/*try {
		char* ptr = new char[0x7fffffff];
		cout << "hello world" << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	return 0;*/
	Test1();
}

