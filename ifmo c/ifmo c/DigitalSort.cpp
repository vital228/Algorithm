#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
vector<string> s;
void CountSort(int k) {
	int ch[26];
	for (int i = 0; i < 26; i++) ch[i] = 0;
	vector<string> s1=s;
	for (int i = 0; i < s1.size(); i++) {
		ch[s1[i][k]-'a']++;
	}
	for (int i = 1; i < 26; i++) {
		ch[i] += ch[i - 1];
	}
	for (int i = s1.size() - 1; i >= 0; i--) {
		s[ch[s1[i][k]-'a']-1] = s1[i];
		ch[s1[i][k]-'a']--;
	}
}

int main() {
	int n, m, faze;
	cin >> n >> m >> faze;
	for (int i = 0; i < n; i++) {
		string sk;
		cin >> sk;
		s.push_back(sk);
	}
	for (int i = m - 1; i >= m - faze; i--) {
		CountSort(i);
	}
	for (int i = 0; i < n; i++) {
		cout << s[i] << '\n';
	}

	cin >> n;
	return 0;
}
