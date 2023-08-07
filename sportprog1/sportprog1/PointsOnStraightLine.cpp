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
	int n,d;
	cin >> n>>d;
	vector<long long> a(n), prev(n + 1);
	long long f, sumf = 0, suml = 0, sum = 0;
	prev[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		prev[i + 1] += prev[i]+ i + 1;
	}
	f = 0;
	for (int i = 1; i < n; i++) {
		while (a[i] - a[f] > d) {
			f++;
		}
		if (i>f+1)
			sum += prev[i-f-1];
	}
	cout << sum;
}