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
	queue<int> q;
	int winner = 0;
	int count = 0;
	int n;
	long long k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		q.push(p);
	}
	while (count < k && winner!=n) {
		if (winner == 0) {
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			if (a > b) {
				winner = a;
				q.push(b);
			}
			else {
				winner = b;
				q.push(a);
			}
			count = 1;
		} 
		else {
			if (winner < q.front()) {
				q.push(winner);
				winner = q.front();
				q.pop();
				count = 1;
			}
			else {
				q.push(q.front());
				q.pop();
				count++;
			}
		}
	}
	cout << winner;
}