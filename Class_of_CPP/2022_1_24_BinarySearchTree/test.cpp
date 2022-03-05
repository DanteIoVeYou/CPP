#define _CRT_SECURE_NO_WARNINGS 1
#include "BSTree.h"
void Test1() {
	//BSTree<int> root;
	//root.Push(1);
	//cout << (2 ^ 3) << endl;
	//cout << (6 ^ 7) << endl;
	K::BSTree<int> tree;
	tree.Insert(1);
	tree.Insert(3);
	tree.Insert(5);
	tree.Insert(7);

	tree.Insert(-7);
	tree.Insert(7);
	tree.Insert(999);
	tree.Insert(9);
	tree.Insert(12);
	tree.InOrder();
	tree.Erase(1);
	tree.InOrder();


	/*tree.Erase(5);
	tree.InOrder();

	tree.Erase(999);
	tree.InOrder();

	tree.Erase(1);
	tree.InOrder();

	tree.Erase(3);
	tree.InOrder();

	tree.Erase(7);
	tree.InOrder();

	tree.Erase(-7);
	tree.InOrder();

	tree.Erase(9);
	tree.InOrder();



	tree.Erase(12);
	tree.InOrder();*/


	//cout << (tree.Find(999))->_val << endl;
}
void Test2() {
	KV::BSTree<string, int> tree;
	vector<string> arr = { "苹果", "香蕉", "苹果", "西瓜" , "梨" };
	for (auto e : arr) {
		KV::BSTreeNode<string, int>* ret = tree.Find(e);
		if (ret == nullptr) {
			tree.Insert(e, 1);
		}
		else {
			ret->_val++;
		}
	}
	tree.InOrder();
}

void Test3() {
	KV::BSTree<string, int> tree;
	vector<string> arr = { "苹果", "香蕉", "苹果", "西瓜" , "梨" };
	for (auto e : arr) {
		tree[e]++;
	}
	tree.InOrder();
}
int main() {
	//Test1();
	Test2();
	Test3();
	return 0;
}


//else if(cur->left!=nullptr && cur->right!=nullptr){
//	if (parent->left == cur) {
//		BTNode* tmpRoot = cur;
//		while (cur->right != nullptr) {
//			BTNode* tmpparent = cur;
//			cur = cur->right;
//			if (cur->right != nullptr) {
//				parent = cur;
//			}
//		}
//		//找到了最右的节点cur
//		tmpRoot->_key = parent->right->_key;
//		delete parent->right;
//		parent->right = nullptr;
//	}
//	else if(parent->right == cur){
//		BTNode* tmpRoot = cur;
//		while (cur->left != nullptr) {
//			BTNode* tmpparent = cur;
//			cur = cur->left;
//			if (cur->left != nullptr) {
//				parent = cur;
//			}
//		}
//		tmpRoot->_key = parent->left->_key;
//		delete parent->left;
//		parent->left == nullptr;
//		
//	}
//}