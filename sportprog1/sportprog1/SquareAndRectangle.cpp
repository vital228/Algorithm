#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct point {
	int x, y;
};
long long p(point a, point b) {
	return (a.x - b.x) * (a.x - b.x)+ (a.y - b.y) * (a.y - b.y);
}
bool gen(vector<point>& sk,vector<int>& flag, int n, int k) {
	if (k==4) {
		vector<point> a;
		for (int i = 0; i < n; i++) {
			if (flag[i] == 1) {
				a.push_back(sk[i]);
			}
		}

		if (p(a[0], a[2]) == p(a[1], a[3]) && p(a[0], a[1]) == p(a[2], a[3]) && p(a[0], a[3]) == p(a[2], a[1])) {
			if (p(a[0], a[2]) == p(a[0], a[3]) || p(a[0], a[1]) == p(a[0], a[3]) || p(a[0], a[2]) == p(a[0], a[1])) {
				vector<int> b;
				for (int i = 0; i < n; i++) {
					if (flag[i] == 0) {
						b.push_back(i);
					}
				}
				if (p(sk[b[0]], sk[b[2]]) == p(sk[b[1]], sk[b[3]]) && p(sk[b[0]], sk[b[1]]) == p(sk[b[2]], sk[b[3]]) && p(sk[b[0]], sk[b[3]]) == p(sk[b[2]], sk[b[1]])) {
					for (int i = 0; i < 4; i++) {
						flag[b[i]] = 2;
					}
					return true;
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (flag[i] == 0) {
				flag[i] = 1;
				bool f=gen(sk, flag, n, k + 1);
				if (f)
					return f;
				flag[i] = 0;
			}
		}
	}
	return false;
}

int main() {
	int n, m;
	vector<point> v(8);
	vector<int> flag(8,0);
	for (int i = 0; i < 8; i++) {
		cin >> v[i].x >> v[i].y;
	}
	bool f=gen(v, flag, 8, 0);
	if (f) {
		cout << "YES\n";
		for (int i = 0; i < 8; i++) {
			if (flag[i] == 1) {
				cout << i + 1<<" ";
			}
		}
		cout << endl;
		for (int i = 0; i < 8; i++) {
			if (flag[i] == 2) {
				cout << i + 1 << " ";
			}
		}
	}
	else {
		cout << "NO\n";
	}
	return 0;
}