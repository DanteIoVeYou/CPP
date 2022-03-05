#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//template <class K>
//struct BSTreeNode {
//
//	K _key;
//	BSTreeNode<K>* _left;
//	BSTreeNode<K>* _right;
//	BSTreeNode(const K& key = 0) :
//		_key = key,
//		_left = nullptr,
//		_right = nullptr{}
//};
//
//
//
//template <class K>
//class BSTree {
//	typedef BSTreeNode Node;
//	BSTree() :
//		_node(nullptr){}
//
//	~BSTree() {
//		_node = nullptr;
//	}
//
//	bool Insert(const K& key) {
//		if (_root == nullptr) {
//			_root = new Node(key);
//			return true;
//		}
//		Node* cur = _root;
//		Node* parent = cur;
//		while (cur) {
//			if (cur->_key > key) {
//				parent = cur;
//				cur = cur->_left;
//			}
//
//			else if (cur->_key < key) {
//				parent = cur;
//				cur = cur->_right;
//			}
//			else {
//				return false;
//			}
//		}
//		
//		if (parent->_left == cur) {
//			parent->_left = new Node(key);
//		}
//		else {
//			parent->_right = new Node(key);
//		}
//		return true;
//	}
//private:
//	Node* _root = nullptr;
//
//};

namespace K {
	template<class K>
	struct BSTreeNode {
		K _key;
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		BSTreeNode(K key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr) {}
		~BSTreeNode() {
			//delete 
			//cout << _key << endl;
		}
	};
	template <class K>
	class BSTree {
	public:
		typedef BSTreeNode<K> Node;
		BSTree()
			:_root(nullptr) {}
		bool Insert(K key) {
			if (_root == nullptr) {
				_root = new Node(key);
			}
			else {
				Node* cur = _root;
				Node* parent = _root;
				while (cur) {
					if (key < cur->_key) {
						parent = cur;
						cur = cur->_left;
					}
					else if (key > cur->_key) {
						parent = cur;
						cur = cur->_right;
					}
					else {
						return false;
					}
				}
				cur = new Node(key);
				if (key < parent->_key) {
					parent->_left = cur;
				}
				else {
					parent->_right = cur;
				}
			}
			return true;
		}

		Node* Find(K key) {
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					cur = cur->_right;
				}
				else {
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(K key) {

			//			5
			//		3		     7
			//	1		4     6		 8
			//0	   2					9

			// 叶子
			// 只有一个孩子
			// 有两个孩子
			Node* parent = _root;
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					parent = cur;
					cur = cur->_right;
				}
				else {
					if (cur->_left == nullptr) {
						// 左孩子为空
						// 1. cur为根
						if (cur == _root) {
							_root = cur->_right;
						}
						// 2. cur不为根
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_right;
							}
							else {
								parent->_right = cur->_right;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else if (cur->_right == nullptr) {
						// 右孩子为空
						// 1. cur为根
						if (cur == _root) {
							_root = cur->_left;
						}
						// 2. cur不为根
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_left;
							}
							else {
								parent->_right = cur->_left;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else {
						// 左右孩子都不为空
						Node* RLNode = cur->_right;
						Node* pRLNode = cur;
						Node* ppRLNode = cur;
						while (RLNode) {
							ppRLNode = pRLNode;
							pRLNode = RLNode;
							RLNode = RLNode->_left;
						}
						cur->_key = pRLNode->_key;
						if (ppRLNode->_left == pRLNode) {
							ppRLNode->_left = pRLNode->_right;
						}
						else {
							ppRLNode->_right = pRLNode->_right;
						}
						delete pRLNode;
						pRLNode = nullptr;
					}
					return true;
				}
			}
			return false;
		}
		void InOrder() {
			_InOrder(_root);
			cout << endl;
		}
		void _InOrder(Node* root) {
			if (root != nullptr) {
				_InOrder(root->_left);
				cout << root->_key << " ";
				_InOrder(root->_right);
			}
		}
	private:
		Node* _root;
	};
}



namespace KV {
	template<class K, class V>
	struct BSTreeNode {
		K _key;
		V _val;
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		BSTreeNode(K key, V val)
			:_key(key)
			, _val(val)
			, _left(nullptr)
			, _right(nullptr) {}
		~BSTreeNode() {
		}
	};
	template <class K, class V>
	class BSTree {
	public:
		typedef BSTreeNode<K, V> Node;
		BSTree()
			:_root(nullptr) {}

		V& operator[](K key) {
			pair<Node*, bool> ret = Insert(key, V());
			return ret.first->_val;

		}
		pair<Node*, bool> Insert(K key, V val) {
			if (_root == nullptr) {
				_root = new Node(key, val);
				return make_pair(_root, true);
			}
			else {
				Node* cur = _root;
				Node* parent = _root;
				while (cur) {
					if (key < cur->_key) {
						parent = cur;
						cur = cur->_left;
					}
					else if (key> cur->_key) {
						parent = cur;
						cur = cur->_right;
					}
					else {
						return make_pair(cur, false);
					}
				}
				cur = new Node(key, val);
				if (key < parent->_key) {
					parent->_left = cur;
				}
				else {
					parent->_right = cur;
				}
				return make_pair(cur, true);
			}
		}

		Node* Find(K key) {
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					cur = cur->_right;
				}
				else {
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(K key) {

			//			5
			//		3		     7
			//	1		4     6		 8
			//0	   2					9

			// 叶子
			// 只有一个孩子
			// 有两个孩子
			Node* parent = _root;
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					parent = cur;
					cur = cur->_right;
				}
				else {
					if (cur->_left == nullptr) {
						// 左孩子为空
						// 1. cur为根
						if (cur == _root) {
							_root = cur->_right;
						}
						// 2. cur不为根
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_right;
							}
							else {
								parent->_right = cur->_right;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else if (cur->_right == nullptr) {
						// 右孩子为空
						// 1. cur为根
						if (cur == _root) {
							_root = cur->_left;
						}
						// 2. cur不为根
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_left;
							}
							else {
								parent->_right = cur->_left;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else {
						// 左右孩子都不为空
						Node* RLNode = cur->_right;
						Node* pRLNode = cur;
						Node* ppRLNode = cur;
						while (RLNode) {
							ppRLNode = pRLNode;
							pRLNode = RLNode;
							RLNode = RLNode->_left;
						}
						cur->_key = pRLNode->_key;
						cur->_val = pRLNode->_val;
						if (ppRLNode->_left == pRLNode) {
							ppRLNode->_left = pRLNode->_right;
						}
						else {
							ppRLNode->_right = pRLNode->_right;
						}
						delete pRLNode;
						pRLNode = nullptr;
					}
					return true;
				}
			}
			return false;
		}
		void InOrder() {
			_InOrder(_root);
			cout << endl;
		}
		void _InOrder(Node* root) {
			if (root != nullptr) {
				_InOrder(root->_left);
				cout << root->_key << ":" << root->_val << " ";
				_InOrder(root->_right);
			}
		}
	private:
		Node* _root;
	};
}