#include <iostream>
#include <vector>
#include<fstream>
#include <string>

using namespace std;
struct Node
{
	int x;
	Node* l;
	Node* r;
	Node* parent;
};
void insert(int x, Node *&MyTree)
{
	if (NULL == MyTree)
	{
		MyTree = new Node;
		MyTree->x = x;
		MyTree->parent = MyTree->l = MyTree->r = NULL;

	}

	if (x < MyTree->x)
	{
		if (MyTree->l != NULL) insert(x, MyTree->l);
		else
		{
			MyTree->l = new Node;
			MyTree->l->l = MyTree->l->r = NULL;
			MyTree->l->x = x;
			MyTree->l->parent = MyTree;
		}
	}

	if (x > MyTree->x)
	{
		if (MyTree->r != NULL) insert(x, MyTree->r);
		else
		{
			MyTree->r = new Node;
			MyTree->r->l = MyTree->r->r = NULL;
			MyTree->r->x = x;
			MyTree->r->parent = MyTree;
		}
	}
}
void deleted(int x, Node*& MyTree) {
	if (MyTree == NULL) {
		return;
	}
	if (MyTree->x == x) {
		Node* p = MyTree->parent;
		if (p == NULL) {
			if (MyTree->l != NULL && MyTree->r != NULL) {
				Node* nxt = MyTree->r;
				while (nxt->l != NULL) {
					nxt = nxt->l;
				}
				MyTree->x = nxt->x;
				deleted(nxt->x, nxt);
				return;
			}
			if (MyTree->l == NULL && MyTree->r == NULL) {
				MyTree = NULL;
				return;
			}

			if (MyTree->l != NULL) {
				MyTree = MyTree->l;
				MyTree->parent = NULL;
			}
			if (MyTree->r != NULL) {
				MyTree = MyTree->r;
				MyTree->parent = NULL;
			}
			return;
		}
		if (MyTree->l == NULL && MyTree->r == NULL) {
			if (p->l == MyTree) {
				p->l = NULL;
			}
			else {
				p->r = NULL;
			}
			MyTree = NULL;
			return;
		}
		if (MyTree->l != NULL && MyTree->r != NULL) {
			Node* nxt = MyTree->r;
			while (nxt->l != NULL) {
				nxt = nxt->l;
			}
			MyTree->x = nxt->x;
			deleted(nxt->x, nxt);
			return;
		}
		if (MyTree->l != NULL || MyTree->r != NULL) {
			if (MyTree->l != NULL) {
				MyTree->l->parent = p;
				if (p->l == MyTree) {
					p->l = MyTree->l;
				}
				else {
					p->r = MyTree->l;
				}
			}
			else {
				MyTree->r->parent = p;
				if (p->l == MyTree) {
					p->l = MyTree->r;
				}
				else {
					p->r = MyTree->r;
				}
			}
		}
		return;
	}
	if (x < MyTree->x) {
		deleted(x, MyTree->l);
	}
	else {
		deleted(x, MyTree->r);
	}
}
bool exists(int x, Node*& MyTree) {
	if (MyTree == NULL) {
		return false;
	}
	if (MyTree->x == x) {
		return true;
	}
	if (x < MyTree->x) {
		return exists(x, MyTree->l);
	}
	else {
		return exists(x, MyTree->r);
	}
}
int next(int x, Node*& MyTree) {
	if (MyTree == NULL) {
		return -1000000001;
	}
	if (x < MyTree->x) {
		int k = next(x, MyTree->l);
		if (k != -1000000001 && k < MyTree->x) {
			return k;
		}
		else {
			return MyTree->x;
		}
	}
	else {
		return next(x, MyTree->r);
	}
}
int prev(int x, Node*& MyTree) {
	if (MyTree == NULL) {
		return -1000000001;
	}
	if (x > MyTree->x) {
		int k = prev(x, MyTree->r);
		if (k != -1000000001 && k > MyTree->x) {
			return k;
		}
		else {
			return MyTree->x;
		}
	}
	else {
		return prev(x, MyTree->l);
	}
}
int main() {
	ifstream fin("bstsimple.in");
	ofstream fout("bstsimple.out");
	int n;
	Node* Tree = NULL;
	bool ftree=true;
	int high = 1;
	string s;
	while (fin >> s) {
		if (s[0] == 'i') {
			int k;
			fin >> k;
			insert(k,Tree);
		}
		if (s[0] == 'd') {
			int k;
			fin>> k;
			deleted(k, Tree);
		}
		if (s[0] == 'e') {
			int k;
			fin >> k;
			if (exists(k, Tree)) {
				fout << "true\n";
			}
			else {
				fout << "false\n";
			}
		}
		if (s[0] == 'n') {
			int k;
			fin >> k;
			k = next(k, Tree);
			if (k == -1000000001) {
				fout << "none\n";
			}
			else {
				fout << k<<'\n';
			}
		}
		if (s[0] == 'p') {
			int k;
			fin >> k;
			k = prev(k, Tree);
			if (k == -1000000001) {
				fout << "none\n";
			}
			else {
				fout << k<<'\n';
			}
		}
	}
	return 0;
}