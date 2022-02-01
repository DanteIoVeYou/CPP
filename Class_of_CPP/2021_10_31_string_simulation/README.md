﻿# 前言
C++引入了面向对象的思想，相比于C语言，一个类能更好地对一些数据结构进行管理和操作。

在C语言中，我们使用字符数组和string.h中的库函数来维护一个字符串，数据与方法分离不说，由于底层的空间是自己维护的，稍不留神就可能造成越界

在C++中，基于面向对象的思想，用来管理字符串的string类便应运而生，从本质上讲，string类就是一个被封装了的**字符数组**

**目录**
- [1.string的简介](#1)
- [2.string的常见接口及模拟实现](#2)
- &nbsp;&nbsp;&nbsp;&nbsp;[2.1 string类对象的常见构造](#2_1)
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[2.2 string类对象的容量操作](#2_2)
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.3 [string类对象获取元素和迭代器的接口](#2_3)
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[2.4 string类对象修改元素接口](#2_4)
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[2.5 string类字符串操作接口](#2_5)
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[2.6 成员常量](#2_6)
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[2.7 非成员函数重载](#2_7)
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[2.8 string类对象比较运算符的重载](#2_8)
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[2.9 string类对象的三种遍历方式](#2_9)
- [3.如何熟悉接口——刷题](#3)
- [4.还想说的话](#4)

<h1 id="1">1.string的简介</h1>
我们学习STL时，文档是我们的利器，学会查文档会让学习事半功倍，以下是两个C++文档网站：

- 官网：[www.cppreference.com](https://en.cppreference.com/w/)
- 常用网站（更新至C++11）：[www.cplusplus.com](https://cplusplus.com/)

string的文档介绍：
1. 字符串是表示字符序列的类。
2. 标准的字符串类提供了对此类对象的支持，其接口类似于标准字符容器的接口，但添加了专门用于操作单字节字符字符串的设计特性。
3. string类是使用char(即作为它的字符类型，使用它的默认char_traits和分配器类型(关于模板的更多信息，请参阅basic_string)。
4. string类是basic_string模板类的一个实例，它使用char来实例化basic_string模板类，并用char_traits和allocator作为basic_string的默认参数(根于更多的模板信息请参考basic_string)。
5. 注意，这个类独立于所使用的编码来处理字节:如果用来处理多字节或变长字符(如UTF-8)的序列，这个类的所有成员(如长度或大小)以及它的迭代器，将仍然按照字节(而不是实际编码的字符)来操作。

```cpp
typedef basic_string<char, char_traits, allocator> string
```

也就是说，我们常提到的string其实是basic_string类模板的使用单字节char的实例化`并typedef成了string`，basic_sring亦可以用双字节的wchar_t实例化，用以处理ascii码无法表示的其他文字，如中文等

<h1 id="2">2.string的常见接口及模拟实现</h1>

<h2 id="2_1">2.1 string类对象的常见构造</h2>

函数名|功能
---|---
[string()](https://cplusplus.com/reference/string/string/string/)|构造空的string类对象，即空字符串
string(const char* s)|用常量字符串来构造string类对象
string(size_t n, char c)|string类对象中包含n个字符c
string(const string&s)|拷贝构造函数
[~string()](https://cplusplus.com/reference/string/string/~string/)|析构函数
[operator=](https://cplusplus.com/reference/string/string/operator=/)|赋值重载，将一个string对象赋值给另一个string对象

**多种构造函数的使用：**
```cpp
void Teststring()
{
string s1; // 构造空的string类对象s1
string s2("hello world"); // 用C格式字符串构造string类对象s2
string s3(s2); // 拷贝构造s3
}
```
**接口的模拟实现：**
- 构造函数

```cpp
//全缺省带参默认构造函数
basic_string(const T* s = "")
	:_size(strlen(s))
	,_capacity(strlen(s)) 
{
	_str = new T[_size + 1];
	strcpy(_str, s);
}
```
- 析构函数
		

```cpp
//析构函数
~basic_string() {
	delete[] _str;
	_str = nullptr;
	_size = 0;
	_capacity = 0;
}
```
- 拷贝构造
		
```cpp
//拷贝构造(现代写法)
basic_string(const basic_string& str)
	: _str(nullptr)
	{
		if (this != &str) {
			basic_string tmp(str._str);
			swap(tmp);
	}
}
```
- 赋值重载

```cpp
//赋值重载(现代写法2)
basic_string& operator=(basic_string str) {
	swap(str);
	return *this;
}
```



<h2 id="2_2">2.2 string类对象的容量操作</h2>

接口名称|接口作用
---|---
[size()](https://cplusplus.com/reference/string/string/size/)|返回字符串有效字符长度（'\0'之前的字符长度）
[length()](https://cplusplus.com/reference/string/string/length/)|同size()
[capacity()](https://cplusplus.com/reference/string/string/capacity/)|返回当前分配给字符串的空间大小
[empty()](https://cplusplus.com/reference/string/string/empty/)|判断字符串是否为空字符串
[reserve(n)](https://cplusplus.com/reference/string/string/reserve/)|重置capacity的大小，为字符串预留空间
[resize(n, c)](https://cplusplus.com/reference/string/string/resize/)|重置有效字符，将有效字符的个数该成n个，多出的空间用字符c填充
[clear()](https://cplusplus.com/reference/string/string/clear/)|清空有效字符，将字符串变为空字符串
注意：
1. size()与length()方法底层实现原理完全相同，引入size()的原因是为了与其他容器的接口保持一致，一般情况下基本都是用size()。
2. clear()只是将string中有效字符清空，不改变底层空间大小。
3. resize(size_t n) 与 resize(size_t n, char c)都是将字符串中有效字符个数改变到n个，不同的是当字符个数增多时：resize(n)用0来填充多出的元素空间，resize(size_t n, char c)用字符c来填充多出的元素空间。注意：resize在改变元素个数时，如果是将元素个数增多，可能会改变底层容量的大小，如果是将元素个数减少，底层空间总大小不变。
4. reserve(size_t res_arg=0)：为string预留空间，不改变有效元素个数，当reserve的参数小于string的底层空间总大小时，reserver不会改变容量大小。

**接口的模拟实现：**
- size()

```cpp
//size()接口
size_t size() const{
	return _size;
}
```
- length()
```cpp
//length()接口
size_t length() const{
	return _size;
}
```
- capacity()

```cpp
//capacity()接口
size_t capacity() const {
	return _capacity;
}
```
- empty()

```cpp
// 判空
bool empty() const {
	return _size == 0;
}
```
- reserve(n)

```cpp
void reserve(int new_capacity) {
	T* tmp = new T[new_capacity + 1];//多开的一个T的大小用来存'\0'
	strcpy(tmp, _str);
	delete[] _str;
	_str = tmp;
	tmp = nullptr;
	_capacity = new_capacity;
	}
```
- resize(n, c)

```cpp
void resize(size_t n, T c = '\0') {
	if (n <= _size) {
		_str[n] = '\0';
		_size = n;
	}
	else {
		if (n > _capacity) {
			reserve(n);	
		}
		for (size_t i = _size; i < n; i++) {
			_str[i] = c;
		}
		_str[n] = '\0'; 
		_size = n;
	}
}
```
- clear()

```cpp
// 清除
void clear() {
	_str[0] = '\0';
	_size = 0;
}
```

<h2 id="2_3">2.3 string类对象获取元素和迭代器的接口</h2>

接口名称|接口作用
---|---
[operator\[ \]](https://cplusplus.com/reference/string/string/operator%5B%5D/)|返回pos位置的字符
[begin()](https://cplusplus.com/reference/string/string/begin/)|返回第一个有效字符的迭代器
[end()](https://cplusplus.com/reference/string/string/end/)|返回最后一个字符下一个位置的迭代器
[rbegin()](https://cplusplus.com/reference/string/string/rbegin/)|返回最后一个有效字符的迭代器
[rend()](https://cplusplus.com/reference/string/string/rend/)|返回第一个字符的前一个位置的迭代器
>注意：在string类里，迭代器就是字符指针
>注意：auto it = rbegin(); it++是让it指向前面一个位置的地址

**接口的模拟实现：**
- operator[]

```cpp
//重载[]
T& operator[](size_t pos) {
	assert(pos < _size);
	return _str[pos];
}
const T& operator[](size_t pos) const{
		assert(pos < _size);
		return _str[pos];
	}
```
- begin() 和 end()

```cpp
typedef T* iterator;
iterator begin() {
	return _str;
}
iterator end() {
	return _str + _size;
}
```

<h2 id="2_4">2.4 string类对象修改元素接口</h2>

接口名称|接口作用
---|---
[push_back()](https://cplusplus.com/reference/string/string/push_back/)|在字符串后尾插字符c
[append()](https://cplusplus.com/reference/string/string/append/)|在字符串后尾插字符串s
[operator+=](https://cplusplus.com/reference/string/string/operator+=/)|在字符串后尾插字符c/字符串s
[insert()](https://cplusplus.com/reference/string/string/insert/)|在字符串下标为pos的位置开始插入n个字符c/字符串s
[erase()](https://cplusplus.com/reference/string/string/erase/)|在字符串下标为pos的位置开始删除n个字符c/字符串s
[swap()](https://cplusplus.com/reference/string/string/swap/)|交换两个类对象
**接口的模拟实现：**
- push_back() / +=

```cpp
//push_back尾插一个字符
void push_back(const T c) {
	if (_size == _capacity) {
		size_t new_capacity = _capacity == 0 ? 4 : 2 * _capacity;
		reserve(new_capacity);
	}
	_str[_size] = c;
	_size++;
	_str[_size] = '\0';
}
// 复用push_back  重载+=字符
void operator+=(const T c) {
	push_back(c);
}
```
- qppend() / +=

```cpp
//append尾插字符串
void append(const T* str) {
		size_t len = strlen(str);
		if (_size + len > _capacity) {
			reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_str[_size + len] = '\0';
		_size += len;
	}
//复用append，重载+=字符串
void operator+=(const T* str) {
	append(str);
}
```
- insert()

```cpp
//插入字符
basic_string& insert(size_t pos, const T c) {
	assert(pos <= _size);
	if (_size == _capacity) {
		size_t new_capacity = _capacity == 0 ? 4 : 2 * _capacity;
		reserve(new_capacity);
	}
	_size++;
	size_t end = _size + 1;
	while (end > pos) {
		_str[end] = _str[end - 1];
		end--;
	}
	_str[pos] = c;
	return *this;
}
//插入字符串
basic_string& insert(size_t pos, const T* s) {
	assert(pos <= _size);
	size_t len = strlen(s);
	if (len + _size > _capacity) {
		reserve(len + _size);
	}
	size_t end = _size + len;
	while (end - len + 1 > pos) {
		_str[end] = _str[end - len];
		end--;
	}
	_size += len;
	memcpy(begin() + pos, s, len * sizeof(T));
	return *this;
}
```
- erase()

```cpp
iterator erase(size_t pos, size_t len = npos) {
	assert(pos < _size);
	if (pos + len >= _size) {
		_str[pos] = '\0';
	}
	else {
		strcpy(begin() + pos, begin() + pos + len);
	}
	_size = strlen(_str);
	return begin() + pos;
}
```
- swap()

```cpp
void swap(basic_string& str) {
	::swap(_size, str._size);
	::swap(_capacity, str._capacity);
	::swap(_str, str._str);
}
```

<h2 id="2_5">2.5 string类字符串操作接口</h2>

接口名称|接口作用
---|---
[find()](https://cplusplus.com/reference/string/string/find/)|从字符串pos位置开始往后找字符c，返回该字符在字符串中的位置，找不到返回npos
[rfind()](https://cplusplus.com/reference/string/string/rfind/)|从字符串pos位置开始往前找字符c，返回该字符在字符串中的位置，找不到返回npos
[c_str()](https://cplusplus.com/reference/string/string/c_str/)|以常量字符串的形式返回string类对象中的字符指针
[substr()](https://cplusplus.com/reference/string/string/substr/)|从pos位置开始往后截取长度为n的子串s，返回新的子串的类；n默认为npos

**接口的模拟实现：**
- find()

```cpp
size_t find(const T c, size_t pos = 0) const {
	assert(pos < _size);
	for (size_t i = pos; i < _size; i++) {
		if (_str[i] == c) {
			return i;
		}
	}
	return npos;
}
size_t find(const T* s, size_t pos = 0) const {
	assert(pos < _size);
	T* ret = strstr(_str + pos, s);
	if (ret == nullptr) {
		return npos;
	}
	else {
		while (*ret != _str[pos]) {
			pos++;
		}
		return pos;
	}
}
```
- c_str()

```cpp
const T* c_str() const {
	return _str;
}
```
- substr()

```cpp
basic_string substr(size_t pos, size_t n = npos) {
	assert(pos < _size);
	basic_string tmp;
	tmp.resize(_size);
	if (pos + n >= _size || n == npos) {
		strcpy(tmp._str, _str + pos);
		_size -= pos + 1;
	}
	else {
		strcpy(tmp._str, _str + pos);
		*(tmp._str + n) = '\0';
		_size = n;
	}
	cout << _size << endl;
	return tmp;
}
```

<h2 id="2_6">2.6 成员常量</h2>

接口名称|接口作用
---|---
npos|static const size_t npos = -1;

**接口的模拟实现：**
- npos

```cpp
static const size_t npos = -1;
```

<h2 id="2_7">2.7 非成员函数重载</h2>

接口名称|接口作用
---|---
[operator+](https://cplusplus.com/reference/string/string/operator+/)|返回一个2个字符串相加的新构造的字符串对象
[operator<<](https://cplusplus.com/reference/string/string/operator%3E%3E/)|输出所有有效字符
[operator>>](https://cplusplus.com/reference/string/string/operator%3C%3C/)|输入，遇到空格或换行终止
[getline()](https://cplusplus.com/reference/string/string/getline/)|输入，遇到换行终止

**接口的模拟实现：**
- operator+
```cpp
//operator+
basic_string operator+(const basic_string& str) {
	basic_string ret(*this);
	ret += str._str;
	return ret;
}
basic_string operator+(const T* s) {
	basic_string ret(*this);
	ret += s;
	return ret;
}
```

- operator<<

```cpp
ostream& operator<<(ostream& out, const basic_string<char>& str) {
	for (size_t i = 0; i < str.size(); i++) {
		out << str[i];
	}
	return out;
}
```

- operator>>
```cpp
istream& operator>>(istream& in, basic_string<char>& str) {
	str.clear();
	char ch;
	ch = in.get();
	while (ch != ' ' && ch != '\n') {
		str += ch;
		ch = in.get();
	}
	return in;
}
```

- getline()

```cpp
istream& getline(istream& in, basic_string<char>& str) {
	str.clear();
	char ch;
	ch = in.get();
	while (ch != '\n') {
		str += ch;
		ch = in.get();
	}
	return in;
}
```

<h2 id="2_8">2.8 string类对象比较运算符的重载</h2>

接口名称|接口作用
---|---
<|小于
==|等于
!=|不等于
\>|大于
\>=|大于等于
<=|小于等于
**接口模拟实现：**
- <

```cpp
bool operator<(const basic_string& str) {
	size_t end = 0;
	while (end < _size && end < str._size) {
		if (_str[end] > str._str[end]) {
			return false;
		}
		else if(_str[end] < str._str[end]){
			return true;
		}
		end++;
	}
	if (end == str._size) {
		return false;
	}
	else {
		return true;
	}
}
```
- ==

```cpp
bool operator==(const basic_string& str) {
	if (_size != str._size) {
		return false;
	}
	size_t end = 0;
	while (end < _size && end < str._size) {
		if (_str[end] != str._str[end]) {
			return false;
		}
		end++;
	}
	return true;
}
```

- !=

```cpp
bool operator!=(const basic_string& str) {
	return !(*this == str);
}
```
- \>

```cpp
bool operator>(const basic_string& str) {
	return !((*this < str) || (*this == str));
}
```

- \>=

```cpp
bool operator>=(const basic_string& str) {
	return !(*this < str);
}
```
- <=
```cpp
bool operator<=(const basic_string& str) {
	return !(*this > str);
}
```

<h2 id="2_9">2.9 string类对象的三种遍历方式</h2>

```cpp
void Teststring()
{
	string s("hello world");
	// 3种遍历方式：
	// 需要注意的以下三种方式除了遍历string对象，还可以遍历是修改string中的字符，
	// 另外以下三种方式对于string而言，第一种使用最多
// 1. for+operator[]
	for(size_t i = 0; i < s.size(); ++i)
		cout<<s[i]<<endl;
// 2.迭代器
	string::iterator it = s.begin();
	while(it != s.end())
	{
		cout<<*it<<endl;
		++it;
	}
	string::reverse_iterator rit = s.rbegin();
	while(rit != s.rend())
	{
		cout<<*rit<<endl;
		rit++;
	}
// 3.范围for
	for(auto ch : s)
		cout << ch << endl;
}
```


<h1 id="3">3.如何熟悉接口——刷题</h1>
刷题必是初学者掌握STL的最佳方法。以题代学，事半功倍。奉上若干string的习题

**牛客网：**

- [字符串转整型数字](https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking)
- [字符串里面最后一个单词的长度](https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking)

**leetcode：**
- [字符串相加](https://leetcode-cn.com/problems/add-strings/)
- [仅仅反转字母](https://leetcode-cn.com/problems/reverse-only-letters/submissions/)
- [找字符串中第一个只出现一次的字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)
- [验证一个字符串是否是回文](https://leetcode-cn.com/problems/valid-palindrome/)
- [字符串相加](https://leetcode-cn.com/problems/add-strings/)
- [反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)
- [反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)
- [字符串相乘](https://leetcode-cn.com/problems/multiply-strings/description/)

<h1 id="4">4.还想说的话</h1>

1. 模拟实现stl是个无聊、耗时的过程，但是能够帮助我们很深刻地理解`指针`、`数据结构` 、`面向对象编程`以及`逻辑思维能力`、`代码能力`

2. 《 STL源码剖析》------侯捷，打算读一读
3. 本博客所有代码：[github](https://github.com/DanteIoVeYou/CPP/tree/main/Class_of_CPP/2021_10_31_string_simulation)、[gitee](https://gitee.com/imdanteking/CPP/tree/main/Class_of_CPP/2021_10_31_string_simulation)
