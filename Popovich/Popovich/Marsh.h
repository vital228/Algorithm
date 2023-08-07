#pragma once
#include <string>
#include <iostream>
using namespace std;
class Toy
{
	int cost = 0;
	string name, category;
	int limitation = 0;
public:
	Toy() {};
	Toy(int n, string s, string e, int t) : cost(n), name(s), category(e), limitation(t) {}
	~Toy() {}
	int getN()
	{
		return cost;
	}
	string getS()
	{
		return name;
	}
	string getE()
	{
		return category;
	}
	int getT()
	{
		return limitation;
	}
	bool operator>(Toy& ob)
	{
		return cost > ob.cost;
	}
	friend istream& operator>>(istream& in, Toy& ob);
	friend ostream& operator<<(ostream& out, const Toy& ob);
	bool CompareToyname(Toy Toy);
	bool CompareToycost(Toy Toy);
	bool CompareToycategory(Toy Toy);
	bool CompareToylimitation(Toy Toy);
};