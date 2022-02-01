#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"
void print(const imdanteking::basic_string<char>& s) {
	for (size_t i = 0; i < s.size(); i++) {
		std::cout << s[i] << " ";
	}
	cout << std::endl;
}
void Teststring()
{
	string s("hello Bit");
	// 3种遍历方式：
	// 需要注意的以下三种方式除了遍历string对象，还可以遍历是修改string中的字符，
	// 另外以下三种方式对于string而言，第一种使用最多
	// 1. for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << endl;
	// 2.迭代器
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << endl;
		rit++;
	}
	// 3.范围for
	for (auto ch : s)
	cout << ch << endl;
}
int main() {
	imdanteking::basic_string<char> aa;
	aa += "erwrwerw";
	//cout << (aa + "uuu") << endl;
	cout << (aa + " x " + aa) << endl;


	//imdanteking::basic_string<char> bb;
	//bb = aa.substr(2,2);
	//cout << bb.size() << endl;
	//aa.erase(0);
	//imdanteking::basic_string<char> a("helloX");
	//a.reserve(10);
	//a.resize(18, 'c');
	//imdanteking::basic_string<char> b;
	//b.resize(20,'r');
	//print(b);
	//a.push_back('X');
	//a += 'G';
	//a.append("hello");
	//a += "hello";
	//b = a;
	////for (auto e : b) {
	////	std::cout << e << " ";
	////}
	////std::cout << std::endl;
	////Teststring();
	//std::string w("qwer");
	//auto a1 = w.begin();
	//auto a2 = w.end();
	//auto a3 = w.rbegin();
	//a3++;
	//auto a4 = w.rend();
	//imdanteking::basic_string<char> s;
	//s += "ruwsr";
	////cout << (s.find('l',5)) << endl;
	//s.insert(0, "wewq");
	//imdanteking::basic_string<char>::iterator ret = s.erase(0);
	////cin >> s;
	//getline(cin, s);
	//cout << s << endl;
	//cout << *ret << endl;
	/*s += "hkfhsjfb";
	cout << s.empty() << endl;
	s.clear();
	cout << s.empty() << endl;
	const char* p = s.c_str();
	return 0;*/
	return 0;
}