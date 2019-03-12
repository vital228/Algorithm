#include<iostream>
#include<fstream>
using namespace std;

int a[30000000];
int main() {
	ifstream fin("kth.in");
	ofstream fout("kth.out");
	int A, B, C,n,k;
	fin >> n >> k >> A >> B >> C >> a[0] >> a[1];
	for (int i = 2; i < n; i++) {
		a[i] = A * a[i - 2] + B * a[i - 1] + C;
	}
	k--;
	int L = 0, R = n-1;
	while (L <= R - 1) {
		int x = a[k];
		int i = L;
		int j = R;
		do {
			while (a[i] < x) 
				i++;
			while (a[j] > x) 
				j--;
			if (i <= j) {
				swap(a[i], a[j]);
				i++;
				j--;
			}
		} while (i <= j);
		if (j < k)
			L = i;
		if (k < i)
			R = j;
	}
	
	fout << a[k];
	//cin >> a[0];
	fin.close();
	fout.close();
	return 0;
}