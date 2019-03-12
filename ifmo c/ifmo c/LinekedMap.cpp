#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int M = 1000013, p1 = 997, p2 = 991, Null = 1000000002, Deleted = 1000000001, p3 = 262139;

struct Map {
	int key=Null,index;
	string value;
	int prev, next;
};
Map Hash[M];
int tail=-1;
ifstream fin("linkedmap.in");
ofstream fout("linkedmap.out");
void insert(int k, string val) {

	bool finsert = false;
	int i = 0;
	long long h = (k * p1) % M;
	while (!finsert && i < M) {
		h = (h + (long long)i * p2) % M;
		h = abs(h);
		if (Hash[h].key == Null || Hash[h].key == Deleted || Hash[h].key == k) {
			if (Hash[h].key != k) {
				Hash[h].key = k;
				Hash[h].value = val;
				if (tail == -1) {
					tail = h;
					Hash[h].prev = -1;
					Hash[h].next = -1;
				}
				else {
					Hash[h].prev = tail;
					Hash[tail].next = h;
					tail = h;
					Hash[h].next = -1;
				}
				finsert = true;
			}
			else {
				Hash[h].value = val;
				finsert = true;
			}
		}
		i++;
	}
}
void excists(int k) {

	bool fexcists = false;
	string s;
	int i = 0;
	long long h = (k * p1) % M;
	while (!fexcists && i < M) {
		h = (h + (long long)i * p2) % M;
		h = abs(h);
		if (Hash[h].key == Null) {
			break;
		}
		if (Hash[h].key == k) {
			fexcists = true;
			s = Hash[h].value;
		}
		i++;
	}
	if (fexcists)
		fout << s << '\n';
	else
		fout << "none\n";
}
void deleted(int k) {

	bool fexcists = false;
	int i = 0;
	int h = (k * p1) % M;
	while (!fexcists && i < M) {
		h = (h + (long long)i * p2) % M;
		h = abs(h);
		if (Hash[h].key == Null) {
			break;
		}
		if (Hash[h].key == k) {
			Hash[h].key = Deleted;
			int pr = Hash[h].prev,nxt=Hash[h].next;
			if (pr != -1) {
				Hash[pr].next = nxt;
			}
			if (nxt != -1) {
				Hash[nxt].prev = pr;
			}
			else {
				tail = pr;
			}
		}
		i++;
	}
}

void prevx(int k){

	bool fexcists = false;
	string s;
	int i = 0;
	long long h = (k * p1) % M;
	while (!fexcists && i < M) {
		h = (h + (long long)i * p2) % M;
		h = abs(h);
		if (Hash[h].key == Null) {
			break;
		}
		if (Hash[h].key == k) {
			fexcists = true;
			int prv;
			prv = Hash[h].prev;
			if (prv != -1) {
				fout<< Hash[prv].value<<'\n';
			}
			else {
				fout << "none\n";
			}
		}
		i++;
	}
	if (!fexcists) {
		fout << "none\n";
	}
}
void nextx(int k) {

	bool fexcists = false;
	string s;
	int i = 0;
	long long h = (k * p1) % M;
	while (!fexcists && i < M) {
		h = (h + (long long)i * p2) % M;
		h = abs(h);
		if (Hash[h].key == Null) {
			break;
		}
		if (Hash[h].key == k) {
			fexcists = true;
			int nxt;
			nxt = Hash[h].next;
			if (nxt != -1) {
				fout << Hash[nxt].value << '\n';
			}
			else {
				fout << "none\n";
			}
		}
		i++;
	}
	if (!fexcists) {
		fout << "none\n";
	}
}

int main() {
	for (int i = 0; i < M; i++) {
		Hash[i].key = Null;
	}
	string s;
	while (fin >> s) {
		string k, k1;

		if (s == "put") {
			fin >> k >> k1;
			int key = 0;
			for (int i = 0; i < k.size(); i++) {
				key = (key * p3 + int(k[i])) % (Deleted - 1);
			}
			insert(key, k1);
		}
		if (s[0] == 'g') {
			fin >> k;
			int key = 0;
			for (int i = 0; i < k.size(); i++) {
				key = (key * p3 + int(k[i])) % (Deleted - 1);
			}
			excists(key);
		}
		if (s[0] == 'd') {
			fin >> k;
			int key = 0;
			for (int i = 0; i < k.size(); i++) {
				key = (key * p3 + int(k[i])) % (Deleted - 1);
			}
			deleted(key);
		}
		if (s == "prev") {
			fin >> k;
			int key = 0;
			for (int i = 0; i < k.size(); i++) {
				key = (key * p3 + int(k[i])) % (Deleted - 1);
			}
			prevx(key);
		}
		if (s[0] == 'n') {
			fin >> k;
			int key = 0;
			for (int i = 0; i < k.size(); i++) {
				key = (key * p3 + int(k[i])) % (Deleted - 1);
			}
			nextx(key);
		}
	}
	fin.close();
	fout.close();
	return 0;
}