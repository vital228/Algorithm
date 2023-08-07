#include<stack>
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

long long pow3(int n) {
	long long t = 1;
	for (int i = 1; i <= n; i++) {
		t *= 3;
	}
	return t;
}

int main() {
	map<char, int> abc;
	for (char i = '0'; i <= '9'; i++) {
		abc[i] = i - 48;
	}
	for (char i = 'A'; i <= 'Z'; i++) {
		abc[i] = i - 'A' + 10;
	}
	for (char i = 'a'; i <= 'z'; i++) {
		abc[i] = i - 'a' + 36;
	}
	abc['-'] = 62;
	abc['_'] = 63;
	string s;
	long long sum = 1;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		unsigned int t = abc[s[i]];
		int count1 = 0;
		for (int j = 0; j < 6; j++) {
			count1 += t % 2;
			t >>= 1;
		}
		count1 = 6 - count1;
		sum *= pow3(count1);
		sum %= 1000000007;
	}
	cout << sum;
	return 0;
}