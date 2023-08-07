#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

class Pie {
	int D;
	int R;
public:	
	Pie(int r, int d) {
		this->R = r;
		this->D = d;
	}
	
	bool isHit(int x, int y, int r) {
		return sqrt(x * x + y * y) - r >= R - D && sqrt(x * x + y * y) + r <= R;
	}

};



int main() {
	int d, r;
	cin >> r >> d;
	Pie lemonPie(r, d);
	int n;
	cin >> n;
	int x, y;
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> r;
		if (lemonPie.isHit(x, y, r)) {
			s++;
		}
	}
	cout << s;
	return 0;
}