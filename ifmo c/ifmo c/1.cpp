
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	float c[100000], b[100000];
	int n;
	ifstream fin("sortland.in");
	ofstream fout("sortland.out");
	fin >> n;
	for (int i = 0; i<n; i++) {
		fin >> c[i];
		b[i] = c[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (c[j + 1] < c[j]) {
				float m = c[j + 1];
				c[j + 1] = c[j];
				c[j] = m;
			}
		}
	}
	for (int i = 0; i<n; i++)
		if (c[0] == b[i])
			fout << i + 1 << " ";
	for (int i = 0; i<n; i++)
		if (c[n / 2] == b[i])
			fout << i + 1 << " ";
	for (int i = 0; i<n; i++)
		if (c[n - 1] == b[i])
			fout << i + 1 << " ";
	fin.close();
	fout.close();
	return 0;
}