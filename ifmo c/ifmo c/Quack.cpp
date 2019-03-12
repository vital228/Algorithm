#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<string> prog;
queue<unsigned short> turing;
map <string, int> labels;
int reg[26];
ifstream fin("quack.in");
ofstream fout("quack.out");
int enque() {
	int k = turing.front();
	turing.pop();
	return k;
}
void readProgram() {
	string s;
	int i = 0;
	
	while (fin>>s) {
			
			if (s[0] == ':') {
				labels.insert(pair<string,int>(s.substr(1), i));
			}
			else {
				prog.push_back(s);
				i++;
			}
	}
}
void solve() {
	readProgram();
	string cur;
	int x, y;
	int a1, a2;
	char c;
	for (int i = 0; i < prog.size(); i++) {
		cur = prog[i];
		switch (cur[0]) {
		case '+':
			a1 = enque();
			a2 = enque();
			turing.push(a1 + a2);
			break;
		case '-':
			a1 = enque();
			a2 = enque();
			turing.push(a1 - a2);
			break;
		case '*':
			a1 = enque();
			a2 = enque();
			turing.push(a1 * a2);
			break;
		case '/':
			x = enque();
			y = enque();
			turing.push(y == 0 ? 0 : x / y);
			break;
		case '%':
			x = enque();
			y = enque();
			turing.push(y == 0 ? 0 : x % y);
			break;
		case '>':
			reg[cur[1] - 'a'] = enque();
			break;
		case '<':
			turing.push(reg[cur[1] - 'a']);
			break;
		case 'P':
			fout<<(cur.length() == 1 ? enque() : reg[cur[1] - 'a']) << '\n';
			break;
		case 'C':
			c = (char)((cur.length() == 1 ? enque() : reg[cur[1] - 'a']) % 255);
			fout<<c;
			break;
		case 'J':
			i = (*labels.find(cur.substr(1))).second - 1;
			break;
		case 'Z':
			if (reg[cur[1] - 'a'] == 0) {
				i = (*labels.find(cur.substr(2))).second - 1;
			}
			break;
		case 'E':
			if (reg[cur[1] - 'a'] == reg[cur[2] - 'a']) {
				i = (*labels.find(cur.substr(2))).second - 1;
			}
			break;
		case 'G':
			if (reg[cur[1] - 'a'] > reg[cur[2] - 'a']) {
				i = (*labels.find(cur.substr(3))).second - 1;
			}
			break;
		case 'Q':
			return;
		default: turing.push(stoi(cur));
		}
	}
}

int main() {
	for (int i = 0; i < 26; i++)
		reg[i] = 0;
	solve();
	fin.close();
	fout.close();
	return 0;
}