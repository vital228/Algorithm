#include <iostream>
#include<vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (n * (n - 1) / 2 <= k) {
		cout << "no solution";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cout << "0 " << i << '\n';
	}
	return 0;
}