#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n, mi,f, l, sum;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) {
			mi = 0;
		}
		else {
			if (i == 1) {
				sum = a[1] - a[0];
				l = 1;
				f = 0;
				if (a[1] < a[0]) {
					mi = 1;
				}
			}
			else {
				if (sum < a[i] - a[mi]) {
					sum = a[i] - a[mi];
					f = mi;
					l = i;
				}
				if (a[i] < a[mi]) {
					mi = i;
				}
			}
		}
	}
	cout << f+1<<" "<<l+1;
	return 0;
}