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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string p;
		cin >> p;
		if (m[p] == 0) {
			m[p] = 1;
			cout << "OK" << '\n';
		}
		else {
			cout << p << m[p] << '\n';
			m[p]++;
		}
	}
}