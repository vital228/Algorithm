#include <iostream>
#include <fstream>

using namespace std;

int main() {

	int n, m;
	int a[100000], q[100000];
	ifstream fin("binsearch.in");
	ofstream fout("binsearch.out");
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}
	fin >> m;
	for (int i = 0; i < m; i++) {
		fin >> q[i];
	}
	fin.close();
	for (int i = 0; i < m; i++) {
		int L = -1, R = n;
		int M;
		while (L < R - 1) {
			M = (L + R) / 2;
			if (a[M] < q[i]) {
				L = M;
			}
			else
				R = M;
		}
		if (a[L + 1] == q[i]) {
			fout << R + 1 << ' ';
			L = -1, R = n;

			while (L < R - 1) {
				M = (L + R) / 2;
				if (a[M] <= q[i]) {
					L = M;
				}
				else
					R = M;
			}
			fout << L + 1 << '\n';
		}
		else
			fout << "-1 -1\n";
	}
	fout.close();
	return 0;
}