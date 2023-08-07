#include <iostream>
#include<vector>
#include<fstream>

using namespace std;
vector<int> res;
long long sum = 0;
void merge(vector<int>& a, int l, int m, int r) {
	int it1 = 0, it2 = 0;
	while (l + it1 < m && m + it2 < r) {
		if (a[l + it1] > a[m + it2]) {
			res[it1 + it2] = a[m + it2];
			sum += m - it1 - l;
			it2++;
		}
		else {
			res[it1 + it2] = a[l + it1];
			it1++;
		}
	}
	while (l + it1 < m) {
		res[it1 + it2] = a[l + it1];
		it1++;
	}
	while (m + it2 < r) {
		res[it1 + it2] = a[m + it2];
		it2++;
	}
	for (int i = 0; i < r - l; i++) {
		a[l + i] = res[i];
	}
}

void sortsliyam(vector<int>& a, int l, int r) {
	if (r - l == 1) return;
	sortsliyam(a, l, (l + r) / 2);
	sortsliyam(a, (l + r) / 2, r);
	merge(a, l, (l + r) / 2, r);
}

int binsearch(vector<int>& a, int key) {
	int l = -1, r = a.size();
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (key > a[m]) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return r;
}

int main() {
	int n;
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	res.resize(n);
	sortsliyam(b, 0, n);
	long long min = sum;
	for (int i = 1; i < n; i++) {
		int km;
		km = binsearch(b, a[i - 1]);
		sum +=(long long)(n - km - 1 - km);
		if (sum < min) {
			min = sum;
		}
	}
	cout << min;
	return 0;
}