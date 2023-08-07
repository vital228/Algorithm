#include <iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

struct point {
	int x, y;
	int id;
};

bool cmd_x(point a, point b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
bool cmd_y(point a,point b) {
	return a.y < b.y;
}

vector<point> res;

void update(point& a, point& b, pair<int, int>& ans, long long& m_dist) {
	long long dist = (long long)(a.x - b.x) * (a.x - b.x) + (long long)(a.y - b.y) * (a.y - b.y);
	if (dist < m_dist) {
		ans = { a.id,b.id };
		m_dist = dist;
	}
}
void find_closest(vector<point>& a, int l, int r, pair<int, int>& ans, long long& m_dist) {
	if (l + 3 >= r) {
		for (int i = l; i < r; ++i) {
			for (int j = i + 1; j < r; ++j) {
				update(a[i], a[j], ans, m_dist);
			}
		}
		sort(a.begin() + l, a.begin() + r, cmd_y);
	}
	else {
		int m = (l + r) / 2;
		find_closest(a, l, m, ans, m_dist);
		find_closest(a, m, r, ans, m_dist);
		merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, res.begin(), cmd_y);
		for (int i = l; i < r; i++) {
			a[i] = res[i - l];
			if (i > l) {
				update(a[i - 1], a[i], ans, m_dist);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<point> a(n);
	res.resize(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		sum += k;
		a[i].x = i;
		a[i].y = sum;
		a[i].id = i;
	}
	long long d = 100000000000;
	pair<int, int> ans = { -1, n };
	find_closest(a, 0, n, ans, d);
	cout << d;
	return 0;
}

