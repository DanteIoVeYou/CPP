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
	// 3�ֱ�����ʽ��
	// ��Ҫע����������ַ�ʽ���˱���string���󣬻����Ա������޸�string�е��ַ���
	// �����������ַ�ʽ����string���ԣ���һ��ʹ�����
	// 1. for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << endl;
	// 2.������
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
	// 3.��Χfor
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