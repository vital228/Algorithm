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
	map<string, string> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (m.find(a) != m.end()) {
			m[b] = m[a];
			m.erase(a);
		}
		else {
			m[b] = a;
		}
	}
	cout << m.size() << endl;
	for (auto it = m.begin(); it != m.end(); it++) {
		auto p = *it;
		cout << p.second << " " << p.first << endl;
	}
}