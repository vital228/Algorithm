#include<iostream>
#include<complex>
#include<math.h>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

const long double PI = acos(-1.0);


void fft(vector<complex<long double>>& a, bool invert) {
	int n = (int)a.size();
	if (n == 1)  return;

	vector<complex<long double>> a0(n / 2), a1(n / 2);
	for (int i = 0; i < n; i += 2) {
		a0[i/2] = a[i];
		a1[i/2] = a[i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);

	long double ang = 2 * PI / n * (invert ? -1 : 1);
	complex<long double> w(1), wn(cos(ang), sin(ang));
	for (int i = 0; i < n / 2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert) {
			a[i] /= 2;
			a[i + n / 2] /= 2;
		}
		w *= wn;
	}
}
void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res) {
	vector<complex<long double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size()))  n *= 2;
	n *= 2;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	for (int i = 0; i < n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);

	res.resize(n);
	for (int i = 0; i < n; ++i)
		res[i] = int(fa[i].real() + 0.5);

}


int main() {
	vector<int> a, b, c;
	ifstream fin("duel.in");
	ofstream fout("duel.out");
	string s;
	int t = 1;
	fin >> s;
	int k = s.size() - 1;
	while (k > 0 && s[k] == '0') {
		k--;
	}
	s.resize(k+1);
	for (int i = 0; i < s.size(); i++) {
		a.push_back(s[s.size() - 1 - i] - 48);
	}
	multiply(a, a, b);
	for (int i = 0; i < b.size(); i+=2) {
		c.push_back( (b[i] - 1) / 2);
	}
	unsigned long long sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[s.size()-1-i] == '1') {
			sum += (long long)c[i];
		}
	}
	fout << sum;
}