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
	multimap<int, int> m;
	vector<int> day;
	int dayNow=0;
	int n;
	int timefirst = 0;
	int count = 1;
	cin >> n;
	day.resize(n);
	for (int i = 0; i < n; i++) {
		int c, t;
		cin >> t >> c;
		if (timefirst == 0) {
			timefirst = t;
		}
		if (dayNow == 0) {
			dayNow = t;
			m.insert(c, i);
		}
		else {
			if (dayNow == t) {
				m.insert(c - t + timefirst, i);
			}
			else {
				day[]
			}
		}
	}
}