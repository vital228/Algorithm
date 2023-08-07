#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
	int c = 0;
	int f = 0;
	int a = 0;
};
const int INF = LONG_MAX;
int main() {
	int n;
	cin >> n;
	vector<vector<edge>> edges(n+1, vector<edge>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			edges[i][j].c = 1;
			cin >> edges[i][j].a;
		}
	}
	int sum = 0;
	vector<int> d(n+1);
	vector<int> p(n+1);
	vector<int> u(n + 1);
	vector<int> v(n + 1);
	for (int iF = 1; iF <= n; iF++) {
		p[0] = iF;
		int j = 0;
		vector<int> minv(n + 1, INF);
		vector<int> used(n + 1, 0);
		do {
			used[j] = 1;
			int i = p[j], add = INF, k;
			for (int jF = 1; jF <= n; jF++) {
				if (!used[jF]) {
					if (edges[i][jF].a - u[i] - v[jF] < minv[jF]) {
						minv[jF] = edges[i][jF].a - u[i] - v[jF];
						d[jF] = j;
					}
					if (minv[jF] < add) {
						add = minv[jF];
						k = jF;
					}
				}
			}
			for (int jF = 0; jF <= n; jF++) {
				if (used[jF]) {
					u[p[jF]] += add;
					v[jF] -= add;
				}
				else {
					minv[jF] -= add;
				}
			}
			j = k;
		} while (p[j] != 0);
		do {
			int k = d[j];
			p[j] = p[k];
			j = k;
		} while (j);
	}

	cout << -v[0] << '\n';
	for (int i = 1; i <= n; i++) {
		cout << p[i] << " " << i << '\n';
	}

}
