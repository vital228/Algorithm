#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

struct Box {
	int weight=0, strong=0;
};
bool cmd(const Box a, const Box b) {

}
int main() {
	int n;
	vector<Box> boxes;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Box box;
		boxes.push_back(box);
		cin >> boxes[i].weight >> boxes[i].strong;
	}
	vector<bool> f(n);
	sort(boxes.front(), boxes.back(), cmd);
	int count = 0;
	int strong = 0;
	while (1) {
		int maxc = 0;
		int imax = -1;
		for (int i = 0; i < n; i++) {
			if (count == 0) {
				if (maxc < boxes[i].strong) {
					maxc = boxes[i].strong;
					imax = i;
				}
			}
			else {
				if (!f[i] && maxc < min(strong - boxes[i].weight, boxes[i].strong)) {
					maxc = min(strong - boxes[i].weight, boxes[i].strong);
					imax = i;
				}
			}
		}
		if (imax == -1) {
			break;
		}
		count++;
		f[imax] = true;
		strong = maxc;
	}
	cout<< count;
	return 0;
}