#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	string strs[] = {"西瓜","西瓜","苹果","梨","苹果","西瓜"};
	map<string, int> countMap;
	for(auto& e: strs) {
		map<string, int>::iterator ret = countMap.find(e);
		if(ret != countMap.end()) {
			ret->second++;	
		}
		else {
			countMap.insert(make_pair(e, 1));
		}
	}
	for(auto e: countMap) {
		cout << e.first << ":" << e.second << endl;	
	}
	return 0;
}

