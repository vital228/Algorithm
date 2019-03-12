#include <iostream>
#include <fstream>

using namespace std;

int mas[100000];
long long sum = 0;
void Merge(int l, int r) {
	int first1=l, first2=(l+r)/2,finish=r;
	int middle = first2;
	int m[100000];
	for (int i = l; i < r; i++) {
		if ((mas[first1] <= mas[first2] && first1<middle) || first2>=finish) {
			m[i] = mas[first1];
			first1++;
		}
		else {
			m[i] = mas[first2];
			sum += middle - first1;
			first2++;
		}
	}
	for (int i = l; i < r; i++)
		mas[i] = m[i];
}

void MergeSort(int l, int r) {
	if (l != r - 1) {
		MergeSort(l, (l + r) / 2);
		MergeSort((l + r) / 2, r);
		Merge(l, r);
	}
}
int main() {
	int n;
	ifstream fin("inversions.in");
	ofstream fout("inversions.out");
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> mas[i];
	}
	MergeSort(0, n);
	fout << sum;
	fin.close();
	fout.close();
	return 0;
}