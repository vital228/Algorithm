#include <iostream>
#include<vector>
#include<map>

using namespace std;

int main() {
	unsigned long long k;
	cin >> k;
	map<unsigned long long,unsigned long long> ans;
	vector<unsigned long long > p,s;
	long long t = k;

	for (long long i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			p.push_back(i);
			if ((k / i) != i) {
				p.push_back(k / i);
				if (i != 1) {
					s.push_back(i);
					s.push_back(k / i);
				}
			}
			else {
				s.push_back(i);
			}
			
		}
	}
	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			if (s[i] * s[j] < k) {
				p.push_back(s[i] * s[j]);
			}
		}
	}
	unsigned long long  k2=k*k;
	for (long long i = 0;  i<p.size(); i++) {
		unsigned long long a, b;
		t = p[i];
		if (k2 % t == 0) {
			b = t + k;
			a = (b * k) / t;
			ans[a] = b;
			ans[b] = a;
		}
	}
	cout << ans.size() << '\n';
	for (auto it = ans.begin(); it != ans.end(); it++) {
		auto i = *it;
		cout << i.first << " " << i.second << '\n';
	}
	return 0;
}
