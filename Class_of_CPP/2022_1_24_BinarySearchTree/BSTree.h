#pragma once
 

template <class K>
struct BSTreeNode {

	K _key;
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	BSTreeNode(const K& val = 0) :
		_key = val,
		_left = nullptr,
		_right = nullptr{}
};



template <class K>
class BSTree {
	typedef BSTreeNode Node;
	BSTree() :
		_node(nullptr){}

	~BSTree() {
		_node = nullptr;
	}

	bool Insert(const K& val) {
		if (_root == nullptr) {
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* parent = cur;
		while (cur) {
			if (cur->_key > val) {
				parent = cur;
				cur = cur->_left;
			}

			else if (cur->_key < val) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				return false;
			}
		}
		
		if (parent->_left == cur) {
			parent->_left = new Node(val);
		}
		else {
			parent->_right = new Node(val);
		}
		return true;
	}
private:
	Node* _root = nullptr;

};