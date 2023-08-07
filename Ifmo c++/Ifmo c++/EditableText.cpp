#include "EditableText.h"
#include <string>
#include <vector>


EditableText::EditableText(std::vector <std::string> t):Text(t)
{
	size = t.size();
	text = t;
}
void EditableText::changeNString(std::string s, int n) {
	n--;
	text[n] = s;
	
}
void EditableText::changeWord(std::string s, int n, int i) {
	n--;
	i--;
	int count = 1;
	std::string nstring = nString(n);
	std::vector<std::string> lexems;
	for (int k = 0; k < nstring.size(); k++) {
		std::string lexem;
		while (k < nstring.size() && nstring[k]!=' ') {
			lexem += nstring[k];
			k++;
		}
		lexems.push_back(lexem);
	}
	lexems[i] = s;
	nstring = "";
	for (int k = 0; k < lexems.size(); k++){
		nstring = nstring + lexems[k]+' ';
	}
	nstring.erase(0,0);
	text[n] = nstring;
}
std::pair<int,int> EditableText::searchWord(std::string s) {
	std::pair<int, int> p;
	for (int i = 0; i < text.size(); i++) {
		std::string nstring = nString(i);
		std::vector<std::string> lexems;
		for (int k = 0; k < nstring.size(); k++) {
			std::string lexem;
			while (k < nstring.size() && nstring[k] != ' ') {
				lexem += nstring[k];
				k++;
			}
			if (lexem == s) {
				p.first = i+1;
				p.second = lexems.size()+1;
				return p;
			}
			lexems.push_back(lexem);
		}
	}
	return p;
}

EditableText::~EditableText()
{
}
