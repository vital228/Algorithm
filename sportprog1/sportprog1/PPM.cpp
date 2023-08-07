#include <iostream>
#include<vector>

using namespace std;
vector<int> res;
long long sum = 0;

int main() {
	long long n, k;
	cin >> n >> k;
	vector<int> a(n, 0);
	int i = 1;
	while (i<n && k > n - i) {
		a[n - i] = i;
		k -= n - i;
		i++;
	}
	a[k] = i;
	i++;
	for (int j = 0; j < n; j++) {
		if (a[j] == 0) {
			a[j] = i;
			i++;
		}
		cout << a[j] << " ";
	}
}