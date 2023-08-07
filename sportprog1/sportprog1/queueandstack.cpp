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
	queue<int> ch;
	stack<int> odd;
	int p;
	cin >> p;
	while (p != 0) {
		if (p % 2 == 0) {
			ch.push(p);
		}
		else {
			odd.push(p);
		}
		cin >> p;
	}
	while (!ch.empty()) {
		cout << ch.front() << " ";
		ch.pop();
	}
	cout << endl;
	while (!odd.empty()) {
		cout << odd.top() << " ";
		odd.pop();
	}
}