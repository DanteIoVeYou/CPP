#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"
void print(const imdanteking::basic_string<char>& s) {
	for (size_t i = 0; i < s.size(); i++) {
		std::cout << s[i] << " ";
	}
	cout << std::endl;
}

int main() {
	/*imdanteking::basic_string<char> aa;
	aa += 'a';*/
	//imdanteking::basic_string<char> a("helloX");
	//a.reserve(10);
	//a.resize(18, 'c');
	//imdanteking::basic_string<char> b;
	//b.resize(20,'r');
	////print(b);
	////imdanteking::basic_string<char> b("ffff");
	///*a.push_back('X');
	//a += 'G';
	//a.append("hello");
	//a += "hello";
	//b = a;*/
	//for (auto e : b) {
	//	std::cout << e << " ";
	//}
	//std::cout << std::endl;
	imdanteking::basic_string<char> s;
	imdanteking::basic_string<char> b;
	s += "ruwsr";
	//cout << (s.find('l',5)) << endl;
	s.insert(0, "wewq");
	imdanteking::basic_string<char>::iterator ret = s.erase(0);
	//cin >> s;
	getline(cin, s);
	cout << s << endl;
	//cout << *ret << endl;
	/*s += "hkfhsjfb";
	cout << s.empty() << endl;
	s.clear();
	cout << s.empty() << endl;
	const char* p = s.c_str();
	return 0;*/
}