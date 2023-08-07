#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	vector<int> num;
	int n=0;
	for (int i = a; i <= b; i++) {
		int sum = 0;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				sum += j;
				if (j!=i/j)
					sum += i / j;
			}
		}
		sum += i;
		if (sum > n) {
			n = sum;
		}
		num.push_back(sum);
	}
	for (int i = a; i <= b; i++) {
		if (num[i-a] == n) {
			cout << i << '\n';
		}
	}
	return 0;
}