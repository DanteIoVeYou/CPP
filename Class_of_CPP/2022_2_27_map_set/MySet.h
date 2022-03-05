#pragma once
#include "RBTree.h"
namespace imdanteking
{
	template<class K>
	class set {
		struct kofvalue {
			const K& operator()(const K& k) {
				return k;
			}
		};
	public:
		typedef typename RBTree<K, K, kofvalue>::iterator iterator;
		iterator begin() {
			return _tree.begin();
		}
		iterator end() {
			return _tree.end();
		}
		set() {}
		bool insert(K value) {
			return _tree.Insert(value).second;
		}
	private:
		RBTree<K, K, kofvalue> _tree;
	};

	void set_test1() {
		set<int> s;
		s.insert(1);
		s.insert(2);
		s.insert(14);
		s.insert(16);
		s.insert(19);

		set<int>::iterator it = s.begin();
		while (it != s.end()) {
			cout << *it << endl;
			++it;
		}
	}
}
