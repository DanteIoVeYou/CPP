#pragma once
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
enum Color{
	BLACK,
	RED
};
template<class Value>
struct RBTreeNode {
	Value _value;
	Color _color;
	RBTreeNode<Value>* _parent;
	RBTreeNode<Value>* _left;
	RBTreeNode<Value>* _right;
	RBTreeNode(const Value& value)
		:_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
		,_color(RED)
		,_value(value)
	{}
};

template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	Node* _node;
	RBTreeIterator(Node* node = nullptr)
		:_node(node)
	{}
	Ref operator*() {
		return _node->_value;
	} 
	Ptr operator->() {
		return &_node->_value;
	}

	RBTreeIterator<T, Ref, Ptr>& operator++() {
		if (_node->_right != nullptr) {
			Node* subLeft = _node->_right;
			while (subLeft->_left) {
				subLeft = subLeft->_left;
			}
			_node = subLeft;
		}
		else {
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right) {
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	bool operator!=(const RBTreeIterator<T, Ref, Ptr>& it) const{
		return _node != it._node;
	}
	bool operator==(const RBTreeIterator<T, Ref, Ptr>& it) const {
		return _node == it._node;
	}
};
template<class K, class V, class KofValue>
class RBTree {
	typedef RBTreeNode<V> Node;
public:
	typedef RBTreeIterator<V, V&, V*> iterator;
	typedef RBTreeIterator<V, const V&, const V*> const_iterator;
	iterator begin() {
		Node* cur = _root;
		while (cur && cur->_left) {
			cur = cur->_left;
		}
		return iterator(cur);
	}
	iterator end() {
		return iterator(nullptr);
	}
	RBTree()
		:_root(nullptr)
	{}
	void RotateR(Node* parent) {
		Node* pparent = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		subL->_right = parent;
		if (subLR) {
			subLR->_parent = parent;
		}
		parent->_parent = subL;

		if (parent == _root) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			subL->_parent = pparent;
			if (pparent->_left == parent) {
				pparent->_left = subL;
			}
			else {
				pparent->_right = subL;
			}
		}
	}
	void RotateL(Node* parent) {
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pparent = parent->_parent;

		parent->_right = subRL;
		subR->_left = parent;

		if (subRL) {
			subRL->_parent = parent;
		}
		parent->_parent = subR;

		if (parent == _root) {
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			subR->_parent = pparent;
			if (pparent->_left == parent) {
				pparent->_left = subR;
			}
			else {
				pparent->_right = subR;
			}
		}
	}
	pair<iterator, bool> Insert(const V& value) {
		if (_root == nullptr) {
			_root = new Node(value);
			_root->_color = BLACK;
			return make_pair(iterator(_root), true);
		}
		 
		Node* parent = nullptr;
		Node* cur = _root;
		KofValue kof;
		while (cur) {
			if (kof(value) < kof(cur->_value)) {
				parent = cur;
				cur = cur->_left;
			}
			else if (kof(value) > kof(cur->_value)) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				return make_pair(iterator(cur), false);
			}
		}
		
		cur = new Node(value);
		Node* newnode = cur;
		cur->_color = RED;
		cur->_parent = parent;
		if (kof(cur->_value) < kof(parent->_value)) {
			parent->_left = cur;
		}
		else {
			parent->_right = cur;
		}

		// 调整红黑树

		// 1.如果新增的节点的父亲是黑色，则不需要处理
		// DO NOTHING

		// 2.如果新增的节点的父亲是红色，则需要分情况处理
		// 2.1.cur为红，parent为红，grandfather为黑，uncle为红
		// 2.2.cur为红，parent为红，grandfather为黑，uncle不存在
		// 2.3.cur为红，parent为红，grandfather为黑，uncle为黑
		while (parent && parent->_color == RED) {
			Node* grandfather = parent->_parent;
			// 左边
			if (parent == grandfather->_left) {
				Node* uncle = grandfather->_right;
				// 情况一： uncle存在且为红，只需要变色
				if (uncle && uncle->_color == RED) {
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = RED;
					cur = grandfather;
					parent = grandfather->_parent;
				}
				// 情况二+三： uncle不存在或者为黑，旋转+变色
				else {
					// 情况二： 单旋+变色
					if (cur == parent->_left) {
						RotateR(grandfather);
						grandfather->_color = RED;
						parent->_color = BLACK;
					}
					// 情况三： 双旋+变色
					else {
						RotateL(parent);
						RotateR(grandfather);
						cur->_color = BLACK;
						grandfather->_color = RED;
					}
					break;
				}
			}
			// 右边
			else {
				Node* uncle = grandfather->_left;
				// 情况一： uncle存在且为红，只需要变色
				if (uncle && uncle->_color == RED) {
					uncle->_color = parent->_color = BLACK;
					grandfather->_color = RED;
					cur = grandfather;
					parent = grandfather->_parent;
				}
				// 情况二+三： uncle不存在或者为黑，旋转+变色
				else {
					// 情况二： 单旋+变色
					if (cur == parent->_right) {
						RotateL(grandfather);
						parent->_color = BLACK;
						grandfather->_color = RED;
					}
					// 情况三： 双旋+变色
					else {
						RotateR(parent);
						RotateL(grandfather);
						cur->_color = BLACK;
						grandfather->_color = RED;
					}
					break;
				}
			}
		}
		_root->_color = BLACK;
		return make_pair(iterator(newnode), true);
	}
	////////////////////////////////////////////////////isBalance()//////////////////////////////////////////
	bool isBalance() {
		if (!_root) {
			return true;
		}
		if (_root->_color == RED) {
			cout << "根节点是红，违反规则1" << endl;
			return false;
		}
		return CheckDoubleRED(_root) && CheckBlackNum(_root, 0, GetBlackNum(_root));
	}
	bool CheckDoubleRED(Node* root) {
		if (root == nullptr) {
			return true;
		}
		if (root->_color == RED && root->_parent->_color == RED) {
			return false;
		}
		return 1 && CheckDoubleRED(root->_left) && CheckDoubleRED(root->_right);
	}
	bool CheckBlackNum(Node* root, int num, int BlackNum) {
		if (root == nullptr) {
			return num == BlackNum;
		}
		if (root->_color == BLACK) {
			return CheckBlackNum(root->_left, num + 1, BlackNum) && CheckBlackNum(root->_right, num + 1, BlackNum);
		}
		else {
			return CheckBlackNum(root->_left, num, BlackNum) && CheckBlackNum(root->_right, num, BlackNum);
		}
	}
	int GetBlackNum(Node* root) {
		int cnt = 0;
		while (root) {
			if (root->_color == BLACK) {
				cnt++;
			}
			root = root->_left;
		}
		return cnt;
	}
	void _Inorder(Node* root) {
		if (root == nullptr) {
			return;
		}
		_Inorder(root->_left);
		cout << "key: " << root->_value.first << " value: " << root->_value.second << " color: " << root->_color << endl;
		_Inorder(root->_right);
	}
	void Inorder() {
		_Inorder(_root);
	}
	////////////////////////////////////////////////////isBalance()//////////////////////////////////////////
private:
	Node* _root;
};