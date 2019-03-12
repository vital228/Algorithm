#include <iostream>
#include <vector>
#include<fstream>
#include <string>
#include <algorithm>

using namespace std;
struct node // структура для представления узлов дерева
{
	int key;
	unsigned int height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};
struct intNode 
{
	int key;
	int l, r;
};
ifstream fin("addition.in");
ofstream fout("addition.out");
vector <intNode> a;

unsigned int height(node* p)
{
	return p ? p->height : 0;
}
int balance_factor(node* p)
{
	return height(p->right) - height(p->left);
}
void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr ? hl : hr) + 1;
}

node* right(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* left(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // балансировка узла p
{
	fixheight(p);
	if (balance_factor(p) == 2)
	{
		if (balance_factor(p->right) < 0)
			p->right = right(p->right);
		return left(p);
	}
	if (balance_factor(p) == -2)
	{
		if (balance_factor(p->left) > 0)
			p->left = left(p->left);
		return right(p);
	}
	return p;
}
node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new node(k);
	if (k<p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}
node* build_tree( int i) {
	node* p= new node(a[i].key);
	if (a[i].l != -1)
		p->left = build_tree(a[i].l);
	if (a[i].r != -1)
		p->right = build_tree(a[i].r);
	fixheight(p);
	return p;
}
int count(node* p) {
	if (!p) return 0;
	return count(p->left) + count(p->right) + 1;
}
void output(node* p, int n) {

	if (p->left == 0) {
		fout << p->key << ' ' << 0 << ' ';
		if (p->right == 0)
			fout << 0 << '\n';
		else
			fout << n + 1 << '\n';
	}
	else {
		if (p->right)
			fout << p->key << ' ' << n + 1 << ' ' << count(p->left) + n + 1 << '\n';
		else
			fout << p->key << ' ' << n + 1 << ' ' << 0 << '\n';
	}
	if (p->left)
		output(p->left,n+1);
	if (p->right)
		output(p->right, count(p->left) + n + 1);
}
int main() {
	int n;
	fin >> n;
	for (int i = 0; i < n; i++) {
		intNode k;
		fin >> k.key >> k.l >> k.r;
		k.l--;
		k.r--;
		a.push_back(k);
	}
	int k;
	fin >> k;
	node* p=0;
	if (n)
		p = build_tree(0);
	p = insert(p, k);
	fout << n + 1 << '\n';
	output(p,1);
	return 0;
}