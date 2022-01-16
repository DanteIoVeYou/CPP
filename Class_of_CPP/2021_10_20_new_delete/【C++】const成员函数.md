# 1.用法
我们想要保证对象被实例化出来之后，在其成员函数中不能修改成员变量的值，我们就要声明`const成员函数`

本质上来讲，const成员函数是用const来修饰隐含的`this指针`

假设我们的Date类有一个打印出日期类的成员函数，我们想让这个函数无法修改对象的私有成员变量，使用const的语法如下：

```cpp
void Print() const{
	//实现
}
```
这样写，就是在隐含的this指针之前加了一个const

```cpp
void Print(const Date* this){ //伪代码，用于说明才把this指针显示写出来，实际上不能显示写出来
	//实现
}
```
# 2.从权限角度谈谈
我们应该有这样一个共识：
>一个LOL职业玩家虽然位置是中单，不怎么玩打野，但是他如果在低端局玩打野，依旧可以统治比赛
>一个青铜玩家虽然玩了10000把中单，但是然他去打职业比赛的中单位，依旧会被打爆

那么对于下面这段代码呢？
>我们的成员函数不是const
>而声明的对象是const

```cpp
#include <iostream>
using namespace std;
class Date
{
public:
	void Display()
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
void Test()
{
	const Date d2;
	d2.Display();
}

int main() 
{
	Test();
	return 0;
}
```
结果编译报错：
![在这里插入图片描述](https://img-blog.csdnimg.cn/c81e5f7f4d544ec896483c6fefa7037a.png#pic_center)
想想看是为什么？

报错报的很明显：
>错误	C2662	“void Date::Display(void)”: 不能将“this”指针从“const Date”转换为“Date &”	

那我们不禁要问了：为什么无法转化呢？

想想我们开头举的打游戏的例子

在这里，加上const，无形之中就像是加上了一把枷锁，把你束缚住了，使得你从王者变成了青铜，丧失了使用诸多秀翻全场的操作的权限

>没有const修饰的成员函数允许this指针指向的对象拥有诸多秀翻全场的操作，用这样的成员函数修改起成员变量来易如反掌

>而当const修饰了成员函数后，这个成员函数那隐含的this指针就被废掉了大半武功，无法操作成员变量了，只能进行低端操作了

>我们实例化的const对象，就好比一个被废了武功的人，他又怎么能取拥有高端操作的能力，去调用没有const修饰的成员函数呢？

>而实例化一个没有const修饰的对象，那么就好比实例化了一个高手，对于有const修饰的成员函数这样的低端操作，高手总是信手拈来的

好了，说了这么多，用专业点的话说，想表达这样一个意思：
>没有const修饰的对象/成员函数，权限是`“读+写”`
>const修饰了对象/成员函数之后，对象/成员函数的权限就变成了`“只读”`，权限降低了

一言蔽之：
>权限高的能操作权限低的，权限低的不能操作权限高的

那么这段代码，大家应该能够悟出来想表达什么了吧：
```cpp
#include <iostream>
using namespace std;
class Date
{
public:
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
void Test()
{
	Date d1;
	d1.Display();
	const Date d2;
	d2.Display();
}

int main() 
{
	Test();
	return 0;
}
```

