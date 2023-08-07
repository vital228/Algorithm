#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> words[26];
	int count = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (words[s[0] - 'a'].size() == 0) {
			count++;
		}
		words[s[0] - 'a'].push_back(s);
	}
	cout << count<<'\n';
	for (int i = 0; i < 26; i++) {
		if (words[i].size() != 0) {
			sort(words[i].begin(), words[i].end());
			for (int j = 0; j < words[i].size(); j++) {
				cout << words[i][j] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}