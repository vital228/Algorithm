#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int M = 1000000, p1 = 997, p2 = 993, Null = 1000000002, Deleted = 1000000001;

int Hash[M];
void insert(int k) {

	bool finsert = false;
	int i = 0;
	long long h = (k * p1) % M;
	while (!finsert && i < M) {
		h = (h + (long long)i * p2) % M;
		h = abs(h);
		if (Hash[h] == Null || Hash[h] == Deleted || Hash[h] == k) {
			Hash[h] = k;
			finsert = true;
		}
		i++;
	}
}
bool excists(int k) {

	bool fexcists = false;
	int i = 0;
	long long h = (k * p1) % M;
	while (!fexcists && i < M) {
		h = (h + (long long)i * p2) % M;
		h = abs(h);
		if (Hash[h] == Null) {
			break;
		}
		if (Hash[h] == k) {
			fexcists = true;
		}
		i++;
	}
	return fexcists;
}
void deleted(int k) {

	bool fexcists = false;
	int i = 0;
	int h = (k * p1) % M;
	while (!fexcists && i < M) {
		h = (h + (long long)i * p2) % M;
		h = abs(h);
		if (Hash[h] == Null) {
			break;
		}
		if (Hash[h] == k) {
			Hash[h] = Deleted;
		}
		i++;
	}
}

int main() {
	for (int i = 0; i < M; i++) {
		Hash[i] = Null;
	}
	string s;
	ifstream fin("set.in");
	ofstream fout("set.out");
	while (fin >> s) {
		int k;
		fin >> k;
		if (s[0] == 'i') {
			insert(k);
		}
		if (s[0] == 'e') {
			if (excists(k))
				fout << "true" << "\n";
			else
				fout << "false" << "\n";
		}
		if (s[0] == 'd') {
			deleted(k);
		}
	}
	fin.close();
	fout.close();
	return 0;
}