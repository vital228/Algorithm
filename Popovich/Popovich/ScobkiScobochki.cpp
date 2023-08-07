#include <iostream>
#include <vector>
#include<string>


using namespace std;

int main() {
	string s;
	cin >> s;
	vector<char> st;
	int sum = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			if (st.size() == 0) { cout << "IMPOSSIBLE"; return 0; }
			else{
				if (s[i] == ')' && st.back() == '(') { st.pop_back(); }
			}
		}
		else {
			st.push_back(s[i]);
		}
	}
	while (!st.empty()) {
		s += ')';
		st.pop_back();
	}
	cout << s;
	return 0;
}
