#pragma once
#include<string>
#include<vector>

class Text
{
protected:
	std::vector <std::string> text;
	int size;
public:
	Text(std::vector <std::string> t);
	Text(const Text &t);
	friend bool operator==(const Text &a, const Text &b) ;
	Text& operator=(const Text &a);

	int countString() const;
	std::string nString(int n) const;
	int countWordInString(int n) const;
	std::string iWordinString(int n, int i) const;
	~Text();
};

