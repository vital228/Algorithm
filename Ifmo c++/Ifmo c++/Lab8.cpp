#include <iostream>
#include <vector>
#include <list>
#include "BST.h"
using namespace std;

template<typename Iter>
void out(Iter first, Iter last) {
	for (; (*first)->value != (*last)->value; ++first) {
		cout<< (*first)->value<<" ";
	}
	cout << (*first)->value << " ";

}

template<typename Iter, typename Pred>
bool one_of(Iter first, Iter last, Pred pred) {
	if (first == last) return true;
	bool is_one = false;
	for (; first != last; ++first) {
		if (pred(*first) && is_one) return false;
		if (pred(*first)) {
			is_one = true;
		}
	}
	return is_one;
}

template<typename Iter, typename Comp>
bool is_palindrome(Iter first, Iter last, Comp comp) {
	Iter last1 = --last;
	++last;
	for (; first != last && first != last1; ++first, --last, --last1) {
		if (!comp(*first, *(last1))) return false;
	}
	return true;
}

template<typename T>
struct equal1s {
	bool operator()(T& a) const {
		return a == 5;
	}
};
template<typename T>
struct equals {
	bool operator()(T& a,T& b) const {
		return a == b;
	}
};

int main() {
	int n;
	BST<int> a;
	a.insert(3);
	a.insert(2);
	a.insert(4);
	out(a.begin(), a.end());
	return 0;
}