#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


set<string> m;
long long gen(string& s, int l, int r, string& k) {
	long long sum = 0;

	
	if (r - l == 2) {
		if (s[l] != s[r - 1]) {
			k[l] = '(';
			k[r - 1] = ')';
			if (m.count(k)) {
				return 0;
			}
			m.insert(k);
			return 1;
		}
		else
			return 0;
	}
	
	if (s[r - 1] != s[l]) {
		k[r - 1] = ')';
		k[l] = '(';
		sum += gen(s, l + 1, r - 1,k);
	}
	if (s[r - 2] != s[r - 1]) {
		k[r - 1] = ')';
		k[r - 2] = '(';
		sum += gen(s, l, r - 2,k);
	}
	if (s[l] != s[l + 1]) {
		k[l+1] = ')';
		k[l] = '(';
		sum += gen(s, l+2, r,k);
	}

	return sum;
}

int main() {
	string s;
	int n;
	cin >> s;
	if (s.size() % 2 == 1) {
		cout << 0;
		return 0;
	}
	n = s.size();
	string k;
	k = s;
	cout<< gen(s, 0, n, k);

	return 0;
}