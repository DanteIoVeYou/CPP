# 1.前言
## 1.1预备知识
- 对于进程地址空间有一定的了解
- 了解C语言的malloc/calloc/realloc/free的用法，功能
![在这里插入图片描述](https://img-blog.csdnimg.cn/976858f8aca2490e83f2f2033e90c810.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBARGFudGVJb1ZlWW91,size_10,color_FFFFFF,t_70,g_se,x_16#pic_left)
## 1.2目录
- new与delete
- operator new与operator delete函数（new/delete的底层实现）
- malloc/free与new/delete的区别
- operator new与operator delete的类专属重载
- 异常捕获
- 定位new

# 2.new与delete
C++较C语言新增了`new`与`delete`两个关键字

`new`与`delete`是C++用来帮助用户在堆上`动态申请/释放内存`的`操作符`（**不是函数**），可以为`int，float`等内置类型变量申请/释放内存，也可以为`类`这样的自定义类型变量申请/释放内存

我们来看一下new/delete的语法
>1. 动态 申请/释放 1个int（内置类型）的空间

```cpp
int* ptr = new int;
delete(ptr);
```
>2. 动态 申请/释放 1个int（内置类型）的空间并初始化为10
```cpp
int* ptr = new int(10);
delete(ptr);
```
>3.  动态 申请/释放 5个int（内置类型）的空间

```cpp
int* ptr = new int[5];
delete[](ptr);
```

今有一类Date：

```cpp
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
private:
	int _year;
	int _month;
	int _day;
};
```
>4. 动态 申请/释放 1个Date（自定义类型）的空间

```cpp
Date* ptr = new Date;
delete(ptr);
```
>5. 动态 申请/释放 1个Date（自定义类型）的空间并初始化
```cpp
Date* ptr = new Date(2, 2, 2);
delete(ptr);
```
>6. 动态 申请/释放 5个Date（自定义类型）的空间

```cpp
Date* ptr = new Date[5];
delete[] ptr;
```
**下面的图片会帮助你更好地理解：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/dbd4e067e2c344239102580896e13939.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBARGFudGVJb1ZlWW91,size_13,color_FFFFFF,t_70,g_se,x_16#pic_left)

# 3.operator new与operator delete函数（new/delete的底层实现）

知道了new/delete的用法，让我们更深入地来看看new/delete的底层实现

我们先来认识一下两个系统提供的`全局函数`：
- operator new
- operator delete

>❗❗❗注意：operator new与operator delete是`函数`，虽然叫operator，但和运算符重载没半毛钱关系

对于new和delete来说：
- new在底层调用operator new全局函数来申请空间
- delete在底层调用operator delete全局函数来释放空间

那么operator new和operator delete的底层又是怎么样的呢？
## 3.1 operator new
operator new全局函数实际通过`malloc来申请空间`，当malloc申请空间成功时直接返回；申请空间失败，尝试执行空 间不足应对措施，如果改应对措施用户设置了，则继续申请，否则`抛异常`

```cpp
void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
{
	// try to allocate size bytes
	void *p;
	while ((p = malloc(size)) == 0)
	if (_callnewh(size) == 0)
	{
		// report no memory
		// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
		static const std::bad_alloc nomem;
		_RAISE(nomem);	
	}
	return (p);
}
```
## 3.2 operator delete
operator delete全局函数最终是通过free来释放空间的

```cpp
void operator delete(void *pUserData)
{
	_CrtMemBlockHeader * pHead;
	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
	if (pUserData == NULL)
		return;
	_mlock(_HEAP_LOCK); /* block other threads */
	__TRY
		/* get a pointer to memory block header */
		pHead = pHdr(pUserData);
		/* verify block type */
		_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
		_free_dbg( pUserData, pHead->nBlockUse );
	__FINALLY
		_munlock(_HEAP_LOCK); /* release other threads */
	__END_TRY_FINALLY
	return;
}
```
而`free`底层调用了`_free_dbg`，free是一个宏函数

```cpp
#define free(p) _free_dbg(p, _NORMAL_BLOCK)
```

# 4.malloc/free	和new/delete的区别
有的人可能大惑不解，既然C语言已经有了`malloc/free`来完成动态内存的管理，C++为什么又要搞出个`new/delete`呢？

简而言之：
（一）对于内置类型
- new和malloc只在开辟内存失败的处理方式上不同，new因为调用了operator new（operator new = malloc + 失败抛异常）会抛异常，而malloc返回NULL
- delete和free是一样的

**（二）对于自定义类型（重要）**
- new = 1.malloc + 2.失败抛异常 + 3.调用构造函数
- delete = 1.调用析构函数 + 2.free

详情请看笔者之前的这篇文章：[【C++】详谈malloc/free和new/delete的区别](https://blog.csdn.net/m0_52640673/article/details/121311335)

# 5.operator new与operator delete函数的类专属重载
我们可以在new/delete一个对象的时候，在该对象所属类中重载一下operator new与operator delete函数，使得new/delete调用operator new/operator delete创建/销毁一个对象的时候，不仅仅是调用malloc/free那么简单，能够根据你自己的需要，干更多的事情

这样做，我们就重载了类专属的operator new与operator delete函数

也就是说，比如类A，我们调用new开辟A，如果A有专属类重载，那new会找到重载了的**类专属的operator new**，而不是全局的::operator new；
>这可以用在我们不想用malloc开辟空间的时候
::表示全局域

>下面代码演示了，针对链表的节点ListNode通过重载类专属 operator new/ operator delete，实现链表节点使用内存池申请和释放内存，提高效率。


```cpp
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;
	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};
int main()
{
	List l;
	return 0
}
```

# 6.异常捕获
刚刚我们谈到，operator new 是对 malloc 的封装，operator new = malloc + 失败抛异常

好，我们在32位系统下，new 2个GB的 堆上的空间，由于我们申请了太多的空间，new申请失败，抛出异常

那么抛异常之后我们怎么捕获异常呢？

用try catch捕获
```cpp
#include <iostream>
using namespace std;

int main() {
	try {
		char* ptr = new char[0x7fffffff];
		cout << "hello world" << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/b8995dd66abf48e6a240fbf818dbf492.png#pic_left)
我们可以看到，在new失败抛异常之后，下面的那句打印hello world 并没有执行，而是直接跳到了捕获异常的位置

我们再看operator new 的实现代码：

```cpp
void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
{
	// try to allocate size bytes
	void *p;
	while ((p = malloc(size)) == 0)
	if (_callnewh(size) == 0)
	{
		// report no memory
		// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
		static const std::bad_alloc nomem;
		_RAISE(nomem);	
	}
	return (p);
}
```
>申请内存失败_callnewh(size) == 0，抛出bad_alloc 类型异常
>申请内存成功，直接返回 void* 的指针

# 7.定位new
我们都知道，一个类的构造函数在这样两种情况下会被调用：
- 栈上实例化对象
- new一个对象
这两种情况下的对于构造函数的调用都是`隐式`调用的

那我们如何`显式`对一块空间调用构造函数进行初始化呢？

我们就需要用到**定位new表达式(placement-new)**

定位new表达式是在`已分配的原始内存空间`中`调用构造函数`初始化一个对象

**使用格式：**
```cpp
new (place_address) type 或者 new (place_address) type(initializer-list)
```
>`place_address`必须是一个`指针`，initializer-list是类型的初始化列表。

**使用场景：**
>定位new表达式在实际中一般是配合`内存池`使用。因为内存池分配出的内存没有初始化，所以如果是自定义类型的对象，需要使用new的定义表达式进行显示调构造函数进行初始化。

```cpp
#include <iostream>
using namespace std;
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
	Test1();
}
```

