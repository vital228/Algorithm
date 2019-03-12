#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n;


int main() {
	ifstream fin("antiqs.in");
	ofstream fout("antiqs.out");
	cin >> n;
	int a[70000], b[70000];
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i < n; i++) {
		if ((i + 1) % 2 == 0) {
			for (int j = i / 2; j < i; j++) {
				b[j] = a[j];
			}
			int k = a[i / 2];
			a[i / 2] = i + 1;
			for (int j = i / 2 + 1; j < i; j++) {
				a[j] = b[j];
			}
			a[i] = k;
		}
		else {
			for (int j = i / 2; j < i; j++) {
				b[j] = a[j];
			}
			int k = a[i / 2];
			a[i / 2] = i + 1;
			for (int j = i / 2 + 1; j < i; j++) {
				a[j] = b[j];
			}
			a[i] = k;
		}
	}

	for (int i = 0; i < n; i++) {
		//fout << a[i] << " ";
		cout << a[i] << " ";
	}
	cin >> a[0];
	return 0;
}
