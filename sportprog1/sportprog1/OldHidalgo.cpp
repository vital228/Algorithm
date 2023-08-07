#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>

using namespace std;
bool cmd(const int a, const int b) {
	return a > b;
}
int main() {
	priority_queue<int, vector<int>, greater<int>> q;
	int n;
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		char a;
		int c;
		cin >> a >> c;
		if (a == 'd') {
			q.push(c);
		}
		else {
			while (q.size() >= c) {
				q.pop();
			}
		}
	}
	char a;
	int c;
	cin >> a >> c;
	if (c <= q.size()) {
		int sum = 0;
		while (!q.empty()) {
			sum += q.top();
			q.pop();
		}
		cout << sum;
	}
	else {
		cout << -1;
	}
	return 0;
}