#include "Text.h"
#include<vector>
#include<string>
#include<string.h>
using namespace std;

Text::Text(std::vector <std::string> t) {
	size = t.size();
	text = t;
}
Text::Text(const Text &t):text(t.text),size(t.size) {

}
bool operator ==(const Text &a, const Text &b) {
	if (a.text == b.text) {
		return true;
	}
	return false;
}
Text& Text::operator=(const Text &a) {
	Text b = a;
	return b;
}
int Text::countString() const {
	return size;
}
string Text::nString(int n) const{
	string s = text[n];
	return s;
}
int Text::countWordInString(int n) const{
	int count=1;
	string s = nString(n);
	if (s.size() == 0) return 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			count++;
		}
	}
	return count;
}
string Text::iWordinString(int n, int i)const {
	string iword;
	string s = nString(n);
	int count = 1;
	for (int k = 0; k < s.size(); k++) {
		if (i == count) {
			iword += s[k];
		}
		if (s[k] == ' ') {
			count++;
		}
	}
	return iword;
}

Text::~Text()
{
}
