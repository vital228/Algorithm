#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
const int M = 100013, N = 1000, p1 = 997, p2 = 993, Null = 1000000002, Deleted = 1000000001,p3=101;

struct MultiMap {
	int key, countHash=0;
	string value;
	vector <vector<int>> Hash;
};
MultiMap Hash[M];
ifstream fin("map.in");
ofstream fout("map.out");
void insert2(int h,string k) {
	int key = 0;
	for (int i = 0; i < k.size(); i++) {
		key = (key * p3 + int(k[i])) % (Hash[h].Hash.size() - 1);
	}
	long long h1 = (key * p1) % Hash[h].Hash.size();
	bool f = false;
	for (int i = 0; i < Hash[h].Hash[h1].size()) {
		if (key == Hash[h].Hash[h1][i])
			return;
	}
	Hash[h].countHash++;
	if (Hash[h].Hash.size() < 2 * Hash[h].countHash) {
		vector<vector<int>> a = Hash[h].Hash;
		vector<int> b;
		if (a.size()>0)
			Hash[h].Hash.assign(a.size()*10,b);
		else 
			Hash[h].Hash.assign((a.size()+1) * 10, b);
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int k1 = a[i][j];
				long long h1 = (k1 * p1) % Hash[h].Hash.size();
				Hash[h].Hash[h1].push_back(k1);
			}
		}
	}
	int key = 0;
	for (int i = 0; i < k.size(); i++) {
		key = (key * p3 + int(k[i])) % (Hash[h].Hash.size() - 1);
	}
	long long h1 = (key * p1) % Hash[h].Hash.size();
	Hash[h].Hash[h1].push_back(key);
}
void insert(int k,string val) {

	bool finsert = false;
	int i = 0;
	long long h = (k * p1) % M;
	while (!finsert && i < M) {
		h = (h + (long long)i * p2) % M;
		h = abs(h);
		if (Hash[h].key == Null || Hash[h].key == Deleted || Hash[h].key == k) {
			Hash[h].key = k;
			Hash[h].value = val;
			finsert = true;
			insert2(h,val);
		}
		i++;
	}

}
bool excists2(int h, string k) {
	int key = 0;
	for (int i = 0; i < k.size(); i++) {
		key = (key * p3 + int(k[i])) % (Hash[h].Hash.size() - 1);
	}
	long long h1 = (key * p1) % Hash[h].Hash.size();
	bool f = false;
	for (int i = 0; i < Hash[h].Hash[h1].size()) {
		if (key == Hash[h].Hash[h1][i])
			return true;
	}
	return false;
}
void excists(int k,string val) {

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
			fexcists = excists2(h,val);
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
		}
		i++;
	}
}

int main() {
	for (int i = 0; i < M; i++) {
		Hash[i].key = Null;
	}
	string s;
	while (fin >> s) {
		string k,k1;
		
		if (s[0] == 'p') {
			fin >> k >> k1;
			int key = 0;
			for (int i = 0; i < k.size(); i++) {
				key =( key * p3 + int(k[i]))%(Deleted-1);
			}
			insert(key,k1);
		}
		if (s[0] == 'g') {
			fin >> k;
			int key = 0;
			for (int i = 0; i < k.size(); i++) {
				key = (key * p3 + int(k[i])) % (Deleted-1);
			}
			excists(key);
		}
		if (s[0] == 'd') {
			fin >> k;
			int key = 0;
			for (int i = 0; i < k.size(); i++) {
				key = (key * p3 + int(k[i])) % (Deleted-1);
			}
			deleted(key);
		}
	}
	fin.close();
	fout.close();
	return 0;
}