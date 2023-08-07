#pragma once
#include "Text.h"
#include <string>
#include <vector>
class EditableText :
	public Text
{
private:

public:
	EditableText(std::vector <std::string> t);
	void changeNString(std::string s, int n);
	void changeWord(std::string s, int n, int i);
	std::pair<int,int> searchWord(std::string s);
	~EditableText();
};

