#pragma once
#include "RBTree.h"
namespace imdanteking
{
	template<class K, class V>
	class map {
		struct kofvalue {
			const K operator()(pair<const K, V> value) {
				return value.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, kofvalue>::iterator iterator;
		map() {}

		pair<iterator, bool> insert(pair<const K, V> value) {
			return _tree.Insert(value);
		}
		iterator begin() {
			return _tree.begin();
		}
		iterator end() {
			return _tree.end();
		}
		V& operator[](const K& key) {
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return (*ret.first).second;
		}
	private:
		RBTree<K, pair<const K, V>, kofvalue> _tree;
	};


	void map_test1() {
		map<string, string> map1;
		map1.insert(make_pair("sort", "����"));
		map1.insert(make_pair("vector", "����"));
		map1.insert(make_pair("apple", "ƻ��"));
		map1.insert(make_pair("apple1", "ƻ��"));
		map1["1231"];
		map1["apple1"] = "����";

		map<string, string>::iterator it = map1.begin();
		while (it != map1.end()) {
			cout << "key: " << it->first << "  value: " << it->second << endl;
			++it;
		}
	}
}