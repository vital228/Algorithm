#include <iostream>
#include <vector>
#include <list>
#include "BST.h"
using namespace std;

template<typename Iter>
void out(Iter first, Iter last) {
	for (; (*first)->value != (*last)->value; ++first) {
		cout << (*first)->value << " ";
	}
	cout << (*first)->value << " ";

}

int main() {
	int n;
	BST<int> a;
	a.insert(3);
	a.insert(2);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.remove(2);

	out(a.begin(), a.end());
	return 0;
}