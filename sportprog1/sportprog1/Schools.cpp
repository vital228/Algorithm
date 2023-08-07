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
	map<string, int> m;
	vector<string> sh;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		string a, b;
		getline(cin, a);
		for (int j = 0; j < a.size(); j++) {
			if (a[j] >= '0' && a[j] <= '9') {
				b += a[j];
			}
		}
		if (b == "") {
			continue;
		}
		if (m[b] != 0) {
			m[b]++;
		}
		else
			m[b] = 1;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		auto p = *it;
		if (p.second <= 5) {
			sh.push_back(p.first);
		}
	}
	cout << sh.size()<<endl;
	for (int i = 0; i<sh.size(); i++) {
		cout << sh[i] << endl;
	}
}