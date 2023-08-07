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
	queue<char> q1, q2;
	string s1, s2;
	int time = 0;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		q1.push(s1[i]);
	}
	for (int i = 0; i < s2.size(); i++) {
		q2.push(s2[i]);
	}
	while (!q1.empty() && !q2.empty()) {
		if (q1.front() == 'L') {
			if (q2.front() == 'L') {
				q1.pop();
				q2.pop();
			}
			else {
				q2.pop();
			}
		}
		else {
			if (q2.front() == 'L') {
				q1.pop();
			}
			else {
				q1.pop();
				q2.pop();
			}
		}
		time++;
	}
	time += q1.size() + q2.size();
	cout << time;
	return 0;
}