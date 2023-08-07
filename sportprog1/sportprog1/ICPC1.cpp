#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int main() {
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		sum += a / b;
		if (a % b > 0) {
			sum++;
		}
	}
	cout << sum;


	return 0;
}
