#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;



int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	vector<unsigned long long> a(n);
	vector<unsigned long long> asort(n);
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}
	asort = a;
	sort(asort.begin(), asort.end());
	unsigned long long mi = asort[0] ^ asort[n - 1];
	unsigned long long l=asort[0], r = asort[n-1];
	for (int i = 1; i < n - 1; i++) {
		unsigned long long t = asort[i] ^ asort[i - 1];
		if (t < mi) {
			mi = t;
			l = asort[i];
			r = asort[i - 1];
		}
		t = asort[i] ^ asort[i + 1];
		if (t < mi) {
			mi = t;
			l = asort[i];
			r = asort[i + 1];
		}
	}
	for (int i = 0; i < n; i++) {
		if (l == a[i]) {
			fout << i + 1 << " ";
			l = -1;
			a[i] = -2;
		}
		if (r == a[i]) {
			fout << i + 1 << " ";
			r = -1;
		}
	}
}
