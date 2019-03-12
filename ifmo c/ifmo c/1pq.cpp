#include<fstream>
#include <vector>
#include <algorithm>
#include<iostream>
#include <string>
using namespace std;
struct element {
	int priority, index;
};
vector <element> a;
vector <int> link;
void Sift(int n, int iSift) {
	bool fSift = true;
	while (iSift <= n / 2 - 1 && fSift) {
		int minChild;
		if (2 * iSift + 2 < n) {
			if (a[2 * iSift + 1].priority < a[2 * iSift + 2].priority)
				minChild = 2 * iSift + 1;
			else
				minChild = 2 * iSift + 2;
			if (a[minChild].priority < a[iSift].priority) {
				swap(link[a[minChild].index], link[a[iSift].index]);
				swap(a[minChild], a[iSift]);
				iSift = minChild;
			}
			else
				fSift = false;

		}
		else {
			minChild = 2 * iSift + 1;
			if (a[minChild].priority < a[iSift].priority) {
				swap(link[a[minChild].index], link[a[iSift].index]);
				swap(a[minChild], a[iSift]);
			}
			iSift = minChild;
		}
	}
}
void HeapSort(int n) {
	//make heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		Sift(n, i);
	}
	//HeapSort
	for (int i = n - 1; i > 0; i--) {
		swap(a[i], a[0]);
		Sift(i, 0);
	}
}
void Push_priorite(element key) {
	a.push_back(key);
	link.push_back(a.size() - 1);
	int i = a.size() - 1;
	while (i > 0 && a[i].priority < a[(i - 1) / 2].priority) {
		swap(link[a[i].index], link[a[(i - 1) / 2].index]);
		swap(a[i], a[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

int main() {
	
	int n;
	string s;
	int i = 0;
	cin >> n;
	while (n>0) {
		cin >> s;
		element key;
		if (s[0] == 'p') {
			cin >> key.priority;
			key.index = a.size();
			Push_priorite(key);
		}
		else {
			link.push_back(-1);
		}
		if (s[0] == 'e') {
			if (a.size()) {
				cout << a[0].priority << '\n';
				swap(link[a[a.size() - 1].index], link[a[0].index]);
				swap(a[a.size() - 1], a[0]);
				link[a[a.size() - 1].index] = -1;
				a.pop_back();
				if (a.size())
					Sift(a.size(), 0);
			}
			else {
				cout << "*\n";
			}
		}
		if (s[0] == 'd') {
			int k, x;
			int index;
			cin >> k >> x;
			k--;
			index = link[k];
			if (a[link[k]].priority < x) {
				a[link[k]].priority = x;
				Sift(a.size() - 1, link[k]);
			}
			else {
				a[link[k]].priority = x;
				int i = link[k];
				while (i > 0 && a[i].priority < a[(i - 1) / 2].priority) {
					swap(link[a[i].index], link[a[(i - 1) / 2].index]);
					swap(a[i], a[(i - 1) / 2]);
					i = (i - 1) / 2;
				}
			}

		}
		n--;
	}
	return 0;

}