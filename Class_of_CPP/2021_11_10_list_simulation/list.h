#pragma once
#include <iostream>
#include <assert.h>
using namespace std;


namespace imdanteking {


	template <class T>
	struct __list_node {
		__list_node(const T& x = T())
			: _next(nullptr)
			, _prev(nullptr)
			, _data(x) {}
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _data;
	};


	template <class T, class Ref, class Ptr>
	struct __list_iterator {
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _node;
		__list_iterator<T, Ref, Ptr>(Node* node)
			: _node(node) {}

		Ref operator*() {
			return _node->_data;
		}
		self operator++() {
			_node = _node->_next;
			return __list_iterator(_node);
		}
		self operator++(int) {
			__list_iterator<T, Ref, Ptr> tmp(_node);
			_node = _node->_next;
			return tmp;
		}
		self operator--() {
			_node = _node->_prev;
			return __list_iterator(_node);
		}
		self operator--(int) {
			__list_iterator<T, Ref, Ptr> tmp(_node);
			_node = _node->_prev;
			return tmp;
		}
		bool operator!=(const self& it2) {
			return (_node != it2._node);
		}
		bool operator==(const self& it2) {
			return (_node == it2._node);
		}
		Ptr operator->() { //In order to get structures' member if T is struct type
			return &_node->_data;
		}
	};




	template <class T>
	class list {
	public:
		typedef __list_node<T> Node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef const __list_iterator<T, const T&, const T*> const_iterator;
		list() 
			:_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
			_head->_data = T();
		}
		list(int n, const T& x = T()) 
			:_head(new Node) {
			_head->_next = _head;
			_head->_prev = _head;
			_head->_data = T();
			Node* cur = _head;
			for(size_t i  = 0; i < (size_t)n; i++) {
				Node* prev = cur;
				Node* next = cur->_next;
				Node* newnode = new Node(x);
				prev->_next = newnode;
				newnode->_prev = prev;
				newnode->_next = next;
				next->_prev = newnode;
				cur = cur->_next;
			}
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last)
			:_head(new Node)
		{
			//Node* cur = _head;
			_head->_next = _head;
			_head->_prev = _head;
			_head->_data = T();
			while(first != last) {
				/*Node* prev = cur;
				Node* next = cur->_next;
				Node* newnode = new Node(*first);
				prev->_next = newnode;
				newnode->_prev = prev;
				newnode->_next = next;
				next->_prev = newnode;
				cur = cur->_next;
				first++;*/
				push_back(*first);
				first++;
			}
		}
		list(const list<T>& lt) 
			:_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
			_head->_data = T();
			for(auto e: lt) {
				push_back(e);
			}
		}
		list<T>& operator=(list lt) {
			swap(lt);
			return *this;
		}
		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}
		//////Iterator////////////////////////////////////////////////////////////////////////////////


		iterator begin() {
			return iterator(_head->_next);
		}
		iterator end() {
			return iterator(_head);
		}
		const_iterator begin() const{
			return const_iterator(_head->_next);
		}
		const_iterator end() const{
			return const_iterator(_head);
		}
		////Capacity/////////////////////////////////////////////////////////////////////////////////
		bool empty() {
			return _head->_next == _head;
		}
		size_t size() {
			size_t ret = 0;
			Node* cur = _head;
			while (cur->_next != _head) {
				cur = cur->_next;
				ret++;
			}
			return ret;
		}
		///Element Access//////////////////////////////////////////////////////////////////////////////////
		const T& back() {
			return _head->_prev->_data;
 		}
		const T& front() {
			return *begin();
		}
		///Modify//////////////////////////////////////////////////////////////////////////////////

		void push_back(const T& val) {
			Node* tail = _head->_prev;
			Node* newnode = new Node(val);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		void pop_back() {
			assert(!empty());
			Node* tail = _head->_prev;
			tail->_prev->_next = _head;
			_head->_prev = tail->_prev;
			delete tail;
			tail = nullptr;

		}
		void push_fornt(const T& val) {
			Node* head = _head->_next;
			Node* newnode = new Node(val);
			_head->_next = newnode;
			newnode->_prev = _head;
			newnode->_next = head;
			head->_prev = newnode;
		}
		void pop_front() {
			assert(!empty());
			Node* head = _head->_next;
			_head->_next = head->_next;
			head->_next->_prev = _head;
			delete head;
			head = nullptr;
		}
		//inserting new elements before the element at the specified position
		//return An iterator that points to the first of the newly inserted elements.
		iterator insert(iterator pos, const T& val) {
			Node* cur = _head;
			while(cur->_next != pos._node) {
				cur = cur->_next;
			}
			Node* prev = cur;
			Node* next = cur->_next;
			Node* newnode = new Node(val);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = next;
			next->_prev = newnode;
			return iterator(newnode);
		}
		//return An iterator pointing to the element that followed the last element erased by the function call
		iterator erase(iterator pos) {
			assert(!empty());
			Node* cur = _head;
			while(cur != pos._node) {
				cur = cur->_next;
			}
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			cur = nullptr;
			return iterator(next);
		}
		iterator erase(iterator first, iterator last) {
			iterator it = first;
			while(it != last) {
				it = erase(it);
			}
			return it;
		}
		void clear() {
			erase(begin(), end());
		}
		void swap(list<T>& lt) {
			if(lt != *this) {
				std::swap(_head, lt._head);
			}
		}
	private:
		Node* _head;
	};

	void print(const list<int>& l) {
		for (const auto& e : l) {
			cout << e << " ";
		}
		cout << endl;
	}
	/// //////////////////////////////////////////////////////////////////////////////////

	void Test1() {
		list<int> lt;

		lt.push_back(1);
		lt.push_back(1);
		lt.push_back(1);
		lt.push_back(1);
		print(lt);
		cout << endl;
	}

	/// //////////////////////////////////////////////////////////////////////////////////
	void Test2() {
		list<int> lt(3, 2);
		cout << lt.size() << endl;
		for (auto e : lt) {
			cout << e << " ";
		}
		cout << endl;
	}
	
}