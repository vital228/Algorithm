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
	deque<char> d, dreverse;
	bool isReverse = false;
	int l, r, n, m;
	cin >> n >> l>>r;
	l--;
	r--;
	string s;
	cin >> s;
	for (int i = l; i <= r; i++) {
		d.push_back(s[i]);
		dreverse.push_front(s[i]);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		char a, b, c;
		cin >> a;
		if (a == 'R') {
			isReverse = !isReverse;
		}
		if (a == 'Q') {
			cin >> b;
			if (b == 'L') {
				if (isReverse) {
					cout << dreverse.front();
				}
				else
					cout << d.front();
			}
			else {
				if (isReverse) {
					cout << dreverse.back();
				}
				else
					cout << d.back();
			}
		}
		if (a == 'S') {
			cin >>b >> c;
			if (b == 'L') {
				if (c == 'L') {
					l--;
					if (isReverse) {
						d.push_back(s[l]);
						dreverse.push_front(s[l]);
					}
					else {
						d.push_front(s[l]);
						dreverse.push_back(s[l]);
					}
				}
				else {
					l++;
					if (isReverse) {
						s[l - 1] = dreverse.front();
						d.pop_back();
						dreverse.pop_front();
					}
					else {
						s[l - 1] = d.front();
						d.pop_front();
						dreverse.pop_back();
					}
				}
			}
			else {
				if (c == 'R') {
					r++;
					if (isReverse) {
						dreverse.push_back(s[r]);
						d.push_front(s[r]);
					}
					else {
						dreverse.push_front(s[r]);
						d.push_back(s[r]);
					}
				}
				else {
					r--;
					if (isReverse) {
						s[r + 1] = d.front();
						dreverse.pop_back();
						d.pop_front();
					}
					else {
						s[r + 1] = dreverse.front();
						dreverse.pop_front();
						d.pop_back();
					}
				}
			}
		}
	}

	return 0;
}