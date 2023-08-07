#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>

using namespace std;

int main() {
	stack<string> s;
	string xml;
	getline(cin, xml);
	for (int i = 0; i < xml.size(); i++){
		string b;
		while (xml[i] != '>') {
			b += xml[i];
			i++;
		}
		if (b[1] == '/') {
			s.pop();
			for (int j = 0; j < s.size(); j++) {
				cout << "  ";
			}
			cout << b<<'>' << endl;
		}
		else {
			for (int j = 0; j < s.size(); j++) {
				cout << "  ";
			}
			cout << b<<">" << endl;
			s.push(b);
		}
	}
}