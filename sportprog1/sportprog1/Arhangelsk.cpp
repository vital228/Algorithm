#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;

int ub(vector<long long>& v, double val) {
	int l = 0, r = v.size() - 1;
	int m = (l + r) / 2;
	while (m < r) {
		if (v[m] > val)
			r = m;
		else
			l = m;
		m = (l + r) / 2 + 1;
	}
	return l;
}

int lb(vector<long long>& v, double val) {
	int l = 0, r = v.size() - 1;
	int m = (l + r) / 2;
	while (m < r) {
		if (v[m] < val)
			l = m;
		else
			r = m;
		m = (l + r) / 2 + 1;
	}
	return m;
}




int main() {
	int n, m;
	cin >> n >> m;
	vector<long long> a, b;
	a.resize(n);
	b.resize(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	int l, r;
	cin >> l >> r;

	sort(b.begin(), b.end());
	long long s = 0;
	for (int i = 0; i < n; ++i) {
		long long cur = a[i];

		if (cur == 0)
		{
			if (0 >= l && 0 <= r) s += m;
			continue;
		}

		if (cur > 0) {
			auto start = lower_bound(b.begin(), b.end(), ceil(l / cur)) - b.begin();
			if (start == m) {
				continue;
			}
			auto end = upper_bound(b.begin(), b.end(), floor(r / cur)) - b.begin();
			if (end == m && b[m - 1] > floor(r / cur)) {
				continue;
			}

			s += max(start, end) - min(end, start);
		}
		else
		{
			auto start = lower_bound(b.begin(), b.end(), floor(l / cur)) - b.begin();
			if (start == m) {
				continue;
			}
			auto end = upper_bound(b.begin(), b.end(), ceil(r / cur)) - b.begin();
			if (end == m && b[m - 1] > floor(r / cur)) {
				continue;
			}
			s += max(start, end) - min(end, start);
		}
	}
	cout << s;
}