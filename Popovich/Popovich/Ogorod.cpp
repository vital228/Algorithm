#include <iostream>
#include <vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m;
	fin >> n >> m;
	vector<vector<int>> og(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			fin >> c;
			if (c == '.') {
				og[i].push_back(0);
			}
			else {
				og[i].push_back(1);
			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (og[i][j] == 1) {
				count++;
				int k = j;
				while (k < m && og[i][k] == 1) {
					og[i][k] = 2;
					k++;
				}
				k = k - j;
				for (int a = i+1; a < i + k; a++) {
					for (int b = j; b < j + k; b++) {
						og[a][b] = 2;
					}
				}
			}
		}
	}
	fout << count;
	return 0;
}