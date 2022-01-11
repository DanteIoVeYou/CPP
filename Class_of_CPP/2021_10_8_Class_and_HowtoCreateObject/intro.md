知识要点

- 什么是类和对象
- 为什么要有面向对象编程
- 成员变量、成员函数
- 封装
- this指针
- 下面代码为什么成功运行了

```c++
class A {
public:
	void Print() {
		cout << "Print()" << endl;
	}
private:
	int _age;
	char _name[20];
};


int main() {
	A* p = nullptr;
	p->Print();
	return 0;
}
```

