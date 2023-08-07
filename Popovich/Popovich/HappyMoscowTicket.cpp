#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class chislo {
public: vector<int> num;
	  const int base = 1000 * 1000 * 1000;
	chislo() {
		num.resize(15);
		for (int i = 0; i < 15; i++) {
			num[i] = 0;
		}
	}

	chislo& operator+=(const chislo &a) {
		int carry = 0;
		for (size_t i = 0; i < max(a.size(), num.size()) || carry; ++i) {
			if (i == num.size())
				num.push_back(0);
			num[i] += carry + (i < a.size() ? a[i] : 0);
			carry = num[i] >= base;
			if (carry)  num[i] -= base;
		}
		return *this;
	}

	const int operator[](int index) const{
		return num[index];
	}

	const size_t size() const{
		return num.size();
	}
	chislo& operator=(const int a) {
		num[0] = a;
		return *this;
	}
	chislo& operator=(const chislo &a) {
		for (size_t i = 0; i < 15; ++i) {
			num[i] = a.num[i];
		}
		return *this;
	}
	void print() {
		bool f = false;
		for (int i = (int)num.size() - 1; i >= 0; --i) {
			if (num[i] > 0 && !f) {
				f = true;
				printf("%d", num[i]);
				continue;
			}
			if (f)
				printf("%09d", num[i]);
		}
	}

};



int main() {
	int n;
	cin >> n;
	chislo d[101][101];
	d[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k <= i * 9;k++) {
			chislo sum;
			for (int j = 0; j < 10 && k-j>=0; j++) {
				sum += d[i - 1][k - j];
			}
			d[i][k] = sum;
		}
	}
	d[n][9 * n / 2].print();
	return 0;
}