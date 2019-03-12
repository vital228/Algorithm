#include <iostream>
#include<vector>


using namespace std;

class new_struct {
	vector<int> buy_cow;
	int one_cow = 4;
	int two_cow = 1;
	int three_cow = 0;
	int four_cow = 0;
	int sum1 = 0;
	int time = 0;
public:
	int sum() {
		return sum1;
	}
	void buy_one() {
		one_cow++;
		buy_cow.push_back(1);
	}
	void buy_two() {
		two_cow++;
		buy_cow.push_back(2);
	}
	void buy_three() {
		three_cow++;
		buy_cow.push_back(3);
	}
	void buy_fout() {
		four_cow++;
		buy_cow.push_back(4);
	}
	void one_hour() {
		sum1 += 1 * one_cow + 6 * two_cow + 32* three_cow + 140 * four_cow;
		time++;
	}
	bool its_all() {
		return sum1 > 10000;
	}
	int gettime() {
		return time;
	}
	void getcoins() {
		cout << time << endl;
		for (int i = 0; i < buy_cow.size(); i++) {
			cout << buy_cow[i] << " ";
		}
	}
};

new_struct point(new_struct a) {
	new_struct a1, a2, a3;
	a.one_hour();
	if (a.its_all()) {
		return a;
	}
	if (a.sum() >= 500) {
		a1 = a;
		a1.buy_one();
		a1 = point(a1);
	}
	if (a.sum() >= 2500) {
		a2 = a;
		a2.buy_two();
		a2 = point(a1);
	}
	if (a.sum() >= 12500) {
		a3 = a;
		a3.buy_three();
		a3 = point(a3);
	}
	a = point(a);
	if (a.gettime() <= a2.gettime() && a.gettime() <= a3.gettime() && a.gettime() <= a1.gettime()) {
		return a;
	}
	else {
		if (a1.gettime() <= a2.gettime() && a1.gettime() <= a3.gettime()) {
			return a1;
		}
		else {
			if (a2.gettime() <= a3.gettime()) {
				return a2;
			}
			else{
				return a3;

			}
		}
	}
}
int main() {
	new_struct a;
	a = point(a);
	a.getcoins();
	int n;
	cin >> n;
	system("pause");
}
