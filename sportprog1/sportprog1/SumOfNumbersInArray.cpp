#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), prev(n + 1);
	int minprev, f,l, sum;
	cin >> a[0];
	prev[0] = 0;
	prev[1] = a[0];
	f = 1;
	l = 1;
	sum = a[0];
	minprev = prev[0] > prev[1] ? 1 : 0;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		prev[i + 1] = prev[i] + a[i];
		if (sum < prev[i + 1] - prev[minprev]) {
			sum = prev[i + 1] - prev[minprev];
			f = minprev + 1;
			l = i + 1;
		}
		if (prev[i + 1] <= prev[minprev]) {
			minprev = i + 1;
		}
	}
	cout << f << " " << l;
}