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
	int n,t;
	cin >> n>>t;
	vector<int> a(n),prev(n+1);
	int f, sum;
	
	prev[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		prev[i + 1] = a[i] + prev[i];
		if (i == 0) {
			if (a[0] <= t) {
				f = 0;
				sum = 1;
			}
			else {
				f = 1;
				sum = 0;
			}
		}
		else {
			while (prev[i + 1] - prev[f] > t) {
				f++;
			}
			if (sum < i + 1 - f) {
				sum = i + 1 - f;
			}
		}
	}
	cout << sum;
}