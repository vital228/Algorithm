#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n;
	int sum=0;
	int k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		sum += k;
	}
	cout << "10 5 ";
	sum -= 15;
	for (int i = 2; i < n; i++) {
		if (sum >= (n - i) * 10 - 2) {
			cout << "10 ";
			sum -= 10;
		}
		else {
			cout << "5 ";
			sum -= 5;
		}
	}
	return 0;
}