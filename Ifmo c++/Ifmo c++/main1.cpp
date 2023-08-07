#include <iostream>

#include<vector>
#include <string>
#include "Geometry_figure.h"
#include"Templ.h"
#include"QueueV.h"

using namespace std;

void geofigure();
int main() {
	/*int n;
	vector <int> nums;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	cout << "\n max: " << max(nums)<<endl;
	vector<double> ds;
	for (int i = 0; i < 5; i++) {
		double d;
		cin >> d;
		ds.push_back(d);
	}
	cout << "\n max: " << max(ds) << endl;
	cin >> n;
	QueueV<int> q(n);
	for (int i = 0; i < 5; i++) {
		int t;
		cin >> t;
		q.push(t);
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
			cout << q.pop() << " ";
	}*/
	geofigure();
	system("pause");
	return 0;
}

void geofigure() {
	GeoObj* g[100];
	int size = 0;
	bool is_true = true;
	while (is_true) {
		cout << "What do you want?\n1. add figure:if ""Circle"" write 0 or if ""Rectangle"" write 1\n2. imagine figure\n3.sum square all figure\n4.sum perimeter all figure\n5.Centre mass system\n6.Memory system\n7.sort figure of mass\n8. End work" << endl;
		int s;
		cin >> s;
		Circle c;
		Rectange r;
		CVector2D centre;
		int sum = 0;
		switch (s)
		{
		case 0: 
			c.initFromDialog();
			g[size] = new Circle(c);
			size++;
			break;
		case 1:
			r.initFromDialog();
			g[size] = new Rectange(r);
			size++;
			break;
		case 2:
			for (int i = 0; i < size; i++) {
				g[i]->draw();
			}
			break;
		case 3:
			for (int i = 0; i < size; i++) {
				sum += g[i]->square();
			}
			cout << sum << endl;
			break;
		case 4:
			for (int i = 0; i < size; i++) {
				sum += g[i]->perimeter();
			}
			cout << sum << endl;
			break;
		case 5:
			centre.x = 0;
			centre.y = 0;
			for (int i = 0; i < size; i++) {
				CVector2D a=g[i]->position();
				centre.x += a.x;
				centre.y += a.y;
			}
			cout << centre.x / size << " " << centre.y / size << endl;
			break;
		case 6:
			for (int i = 0; i < size; i++) {
				sum += g[i]->size();
			}
			cout << sum << endl;
			break;
		case 7:
			for (int i = 1; i < size; i++) {
				for (int j = 0; j < size - i; j++) {
					if (g[j]->mass() > g[j + 1]->mass()) {
						GeoObj* k = g[j];
						g[j] = g[j + 1];
						g[j + 1] = k;
					}
				}
			}
			break;
		case 8:
			is_true = false;
		default:
			break;
		}
	}
}