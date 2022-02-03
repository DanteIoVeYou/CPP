#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"
int main() {
	//int arr[] = {1,2,3,4,5,56,1};
	//imdanteking::vector<int> a(arr,arr + 2);
	////imdanteking::vector<int> a;
	//a.insert(a.begin(), 1);
	//a.insert(a.begin() + a.size(), 6);

	//imdanteking::vector<int> b(a);
	//imdanteking::vector<int> c;
	//c = b;
	imdanteking::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	/*v.resize(1);
	v.resize(4,1);
	v.resize(5);*/

	imdanteking::vector<int> v2(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;

	////////////////////////////erase///////////////////////////////////////////

	v.erase(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]<< " ";
	}
	cout << endl;
	////////////////////////////pop_back///////////////////////////////////////////////

	v2.pop_back();
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
	/////////////////////////////clear//////////////////////////////////////////////

	v2.clear();
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
	//bit::vector<int> a(arr, arr+4);
	//bit::vector<int> b(a);
	//bit::vector<int> c;
	//c = b;



	return 0;
}