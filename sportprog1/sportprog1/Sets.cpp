#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>

using namespace std;

int main() {
	set<int> a;
	set<int> b;
	vector<int> inter;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		a.insert(p);
	}
	for (int i = 0; i < k; i++) {
		int p;
		cin >> p;
		b.insert(p);
	}
	for (auto it = a.begin(); it != a.end(); it++) {
		if (b.count(*it)) {
			inter.push_back(*it);
		}
	}
	cout << "INTERSECTION: " << inter.size()<<endl;
	for (int i = 0; i < inter.size(); i++) {
		cout << inter[i] << " ";
	}
	set<int> c=b;
	for (auto it = a.begin(); it != a.end(); it++) {
		if (!c.count(*it)) {
			c.insert(*it);
		}
	}
	cout<<endl << "UNION: " << c.size() << endl;;
	for (auto it = c.begin(); it != c.end(); it++) {
		cout << *it << " ";
	}
	c = a;
	for (auto it = a.begin(); it != a.end(); it++) {
		if (b.count(*it)) {
			c.erase(*it);
		}
	}
	cout<<endl << "A SUBTRACT B: " << c.size()<<endl;
	for (auto it = c.begin(); it != c.end(); it++) {
		cout << *it << " ";
	}
}