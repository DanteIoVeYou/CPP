#define _CRT_SECURE_NO_WARNINGS 1
#include "BSTree.h"

int main() {
	BSTree<int> root;
	root.Push(1);
	return 0;
}


else if(cur->left!=nullptr && cur->right!=nullptr){
	if (parent->left == cur) {
		BTNode* tmpRoot = cur;
		while (cur->right != nullptr) {
			BTNode* tmpparent = cur;
			cur = cur->right;
			if (cur->right != nullptr) {
				parent = cur;
			}
		}
		//找到了最右的节点cur
		tmpRoot->_key = parent->right->_key;
		delete parent->right;
		parent->right = nullptr;
	}
	else if(parent->right == cur){
		BTNode* tmpRoot = cur;
		while (cur->left != nullptr) {
			BTNode* tmpparent = cur;
			cur = cur->left;
			if (cur->left != nullptr) {
				parent = cur;
			}
		}
		tmpRoot->_key = parent->left->_key;
		delete parent->left;
		parent->left == nullptr;
		
	}
}