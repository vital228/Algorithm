#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct point {
	int q;
	vector<int> chief;
};

bool cmd(const point a, const point b) {
	return b.q < a.q;
}
int main() {
	int n;
	cin >> n;
	vector<point> ch(n);
	for (int i = 0; i < n; i++) {
		cin >> ch[i].q;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ch[b - 1].chief.push_back(c);
	}
	sort(ch.begin(), ch.end(), cmd);
	int sum = 0;
	for (int i = 1; i < n; i++) {
		int min = 1000001;
		for (int j = 0; j < ch[i].chief.size(); j++) {
			if (ch[i].chief[j] < min) {
				min = ch[i].chief[j];
			}
		}
		if (min == 1000001) {
			cout << -1;
			return 0;
		}
		sum+=min;
	}
	cout << sum;
}