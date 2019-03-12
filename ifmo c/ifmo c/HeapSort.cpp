#include<fstream>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;
vector <int> a;
void Sift(int n, int iSift) {
	bool fSift = true;
	while (iSift <= n / 2 - 1 && fSift) {
		int minChild;
		if (2 * iSift + 2 < n) {
			if (a[2 * iSift + 1] < a[2 * iSift + 2]) 
				minChild = 2 * iSift + 1;
			else
				minChild = 2 * iSift + 2;
			if (a[minChild] < a[iSift]) {
				swap(a[minChild], a[iSift]);
				iSift = minChild;
			}
			else
				fSift = false;
			
		}
		else {
			minChild = 2 * iSift + 1;
			if (a[minChild] < a[iSift]) 
				swap(a[minChild], a[iSift]);
			iSift = minChild;
		}
	}
}
void HeapSort(int n) {
	//make heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		Sift(n, i);
	}
	//HeapSort
	for (int i = n - 1; i > 0; i--) {
		swap(a[i], a[0]);
		Sift(i, 0);
	}
}

int main() {
	ifstream fin("sort.in");
	ofstream fout("sort.out");
	int n;
	fin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		fin >> k;
		a.push_back(k);
	}
	HeapSort(n);
	for (int i = n - 1; i >= 0; i--) {
		fout << a[i] << ' ';
	}
	
	fin.close();
	fout.close();
	return 0;

}