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
	int n;
	cin >> n;
	vector<long long> a(n), prev(n + 1);
	long long f, sumf=0,suml=0, sum=0;
	prev[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
	}
	int j = n;
	for (int i = 0; i < j; i++) {
		sumf += a[i];
		while (i<j-1 && sumf > suml) {
			suml += a[j-1];
			j--;
		}
		if (sumf == suml) {
			sum = sumf;
		}
	}
	cout << sum;
}
