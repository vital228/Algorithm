#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main() {
	for (int j = 8; j <= 20; j++) {
		string s = to_string(j);
		ifstream fin(s);
		int n, m;
		fin >> n >> m;
		vector<double> x(n), y(n);
		for (int i = 0; i < n; i++) {
			fin >> x[i] >> y[i];
		}
		if (m == 1) {
			fin.close();
			ofstream fout(s);
			fout << n << " " << 0 << endl;
			for (int i = 0; i < n; i++) {
				fout << x[i] /5 << " " << y[i] /5 << endl;
			}
		}
		else {
			vector<int> ans(n + 1);
			cout << s << endl;
			cout << "{";
			for (int i = 0; i < m; i++) {
				int a, b, c;
				fin >> a >> b >> c;
				ans[i] = a;
				cout << a << ", ";
			}
			cout << ans[0] << "};"<<endl;

		}
	}
}