#pragma once
#include <iostream>


template<class T, class Compare = std::less<T>>
class BST
{
	struct Node {
		T value;
		unsigned int height;
		Node* parent;
		Node* left;
		Node* right;
		Node(T key) { value = key; left = right = parent = NULL; height = 1; }
	};
	unsigned char height(Node* p)
	{
		return p ? p->height : 0;
	}
	int bfactor(Node* p)
	{
		return height(p->right) - height(p->left);
	}
	void fixheight(Node* p)
	{
		unsigned int hl = height(p->left);
		unsigned int hr = height(p->right);
		p->height = (hl > hr ? hl : hr) + 1;
	}
	Node* rotateright(Node *p) // правый поворот вокруг p
	{
		Node* q = p->left;
		Node* par = p->parent;
		p->left = q->right;
		q->right = p;
		p->parent = q;
		q->parent = par;
		fixheight(p);
		fixheight(q);
		return q;
	}
	Node* rotateleft(Node * q) // левый поворот вокруг q
	{
		Node* p = q->right;
		Node* par = q->parent;
		q->right = p->left;
		p->left = q;
		q->parent = p;
		p->parent = par;
		fixheight(q);
		fixheight(p);
		return p;
	}
	Node* balance(Node* p) // балансировка узла p
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0) {
				p->right = rotateright(p->right);

			}
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0) {
				p->left = rotateleft(p->left);
			}
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}
	Node* insert_(Node* p, T k) // вставка ключа k в дерево с корнем p
	{
		if (p == NULL) {
			return new Node(k);
		}
		if (k < p->value) {
			p->left = insert_(p->left, k);
			p->left->parent = p;
		}
		else {
			p->right = insert_(p->right, k);
			p->right->parent = p;
		}
		return balance(p);
	}
	Node* findmin(Node* p) // поиск узла с минимальным ключом в дереве p 
	{
		return p->left ? findmin(p->left) : p;
	}
	Node* removemin(Node* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->left == 0)
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}
	Node* remove_(Node* p, T k) // удаление ключа k из дерева p
	{
		if (!p) return 0;
		if (k < p->value)
			p->left = remove_(p->left, k);
		else if (k > p->value)
			p->right = remove_(p->right, k);
		else //  k == p->value
		{
			Node* q = p->left;
			Node* r = p->right;
			Node* par = p->parent;
			delete p;
			if (!r) return q;
			Node* min = findmin(r);
			min->right = removemin(r);
			min->left = q;
			min->parent = par;
			return balance(min);
		}
		return balance(p);
	}
	Node* find_(Node* p, T k) {
		if (p==NULL) return 0;
		if (k < p->value)
			return find_(p->left, k);
		if (k > p->value)
			return find_(p->right, k);
		return p;
	}
	Node* root;
	size_t size;
public:
	BST() {
		root = NULL;
	}
	BST(const BST & a) {
		this->root = a.root;
	}
	BST& operator=(const BST & a) {
		return a;
	}

	struct iterator 
	{
		Node* cur;
		iterator(Node* p = nullptr) : cur(p) {}
		Node* operator *() { return cur; }
		iterator& operator ++() {
			if (cur->parent == NULL) {
				cur = cur->right;
				return *this;
			}
			if (cur->parent->left == cur) {
				if (cur->right) {
					cur = cur->right;
					while (cur->left) {
						cur = cur->left;
					}
				}
				else {
					cur = cur->parent;
				}
				return *this;
			}
			else {

				if (cur->right) {
					cur = cur->right;
					while (cur->left) {
						cur = cur->left;
					}
				}
				else {
					while (cur->parent != NULL && cur->parent->left == cur) {
						cur = cur->parent;
					}
					if (cur->parent != NULL) {
						cur = cur->parent;
					}
				}
				return *this;
			}
		}
		iterator& operator --() {
			if (cur->parent->right == cur) {
				if (cur->left) {
					cur = cur->left;
					while (cur->right) {
						cur = cur->right;
					}
				}
				else {
					cur = cur->parent;
				}
				return *this;
			}
			else {
				if (cur->left) {
					cur = cur->left;
					while (cur->right) {
						cur = cur->right;
					}
				}
				else {
					while (cur->parent != NULL && cur->parent->right == cur) {
						cur = cur->parent;
					}
					if (cur->parent != NULL) {
						cur = cur->parent;
					}
				}
				return *this;
			}
		}
	};
	struct const_iterator {
		Node* cur;
		const_iterator(Node* p) :cur(p){}
		Node* operator*()const {
			return *cur;
		}
	};
	template<class InputIt>
	void assign(InputIt first, InputIt last) {
		Node* cur = *(first);
		while (cur->parent) {
			cur = cur->parent;
		}
		root = cur;
	}
	iterator begin() {
		Node* cur = root;
		while (cur->left!=NULL)
		{
			cur = cur->left;
		}
		return iterator(cur);
	}
	const_iterator cbegin() {
		Node* cur = root;
		while (cur->left)
		{
			cur = cur->left;
		}
		return const_iterator(cur);
	}
	iterator end() {
		Node* cur = root;
		while (cur->right!=NULL)
		{
			cur = cur->right;
		}
		return iterator(cur);
	}
	const_iterator cend() {
		Node* cur = root;
		while (cur->right)
		{
			cur = cur->right;
		}
		return const_iterator(cur);
	}
	iterator insert(const T& value) {
		size++;
		root=insert_(root, value);
		return iterator(root);
	}
	iterator remove(const T& value) {
		size--;
		root = remove_(root, value);
		return iterator(root);
	}
	iterator find(const T& value) {
		return iterator(find_(root, value));
	}
	const_iterator find(const T& value) const {
		return const_iterator(find_(root, value));
	}
	bool empty() const {
		return begin() == end();
	}
};

