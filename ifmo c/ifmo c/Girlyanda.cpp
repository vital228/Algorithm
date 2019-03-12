#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream> 
#include <string>

using namespace std;

int n;
vector<double> h;

double B()
{
	double l = 0, r = h[0];
	while (r - l > 0.000001) {
		h[1] = (l + r) / 2;
		bool Up = true;
		for (int i = 2; i < n; i++) {
			h[i] = 2 * h[i - 1] - h[i - 2] + 2;
			if (h[i] < 0) {
				Up = false;
				break;
			}
		}
		if (Up) {
			r = h[1];
		}
		else {
			l = h[1];
		}


	}
	return h[n - 1];

}
int main()
{
	ifstream fin("garland.in");
	ofstream fout("garland.out");
	
	fin >> n;
	h.assign(n,0);
	fin >> h[0];
	double a = B();
	fout.precision(2);
	fout << fixed << a;
	
	fin.close();
	fout.close();
	return 0;
}