#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <cassert>

using namespace std;

class Matrix {
	vector<vector<long long>> arr;
public:
	static int n;
	Matrix() {
		for (int i = 0; i < n; i++) {
			vector<long long> t(n, 0);
			arr.push_back(t);
		}
	}

	const vector<long long>& operator[](int index) const {
		assert(index < n);
		return arr[index];
	}

	vector<long long>& operator[](int index) {
		assert(index < n);
		return arr[index];
	}

	

	friend Matrix operator+(const Matrix& a, const Matrix& b) {
		Matrix tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = a[i][j]+b[i][j];
			}
		}
		return tmp;
	}

	friend Matrix operator-(const Matrix& a, const Matrix& b) {
		Matrix tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = a[i][j] - b[i][j];
			}
		}
		return tmp;
	}
	friend Matrix operator*(int k, const Matrix& a) {
		Matrix tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = k * a[i][j];
			}
		}
		return tmp;
	}
	friend Matrix operator*(const Matrix& a, const Matrix& b) {
		Matrix tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					tmp[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		return tmp;
	}
	
	Matrix& operator=(const Matrix& a) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = a[i][j];
			}
		}
		return *this;
	}

	
	friend std::ostream& operator<< (std::ostream& out, const Matrix& a)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				out << a[i][j]<<" ";
			}
			out << '\n';
		}
		return out;
	}
	friend std::istream& operator>> (std::istream& in, Matrix& a)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				in >> a[i][j];
			}
		}
		return in;
	}
};

int Matrix::n = 0;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> Matrix::n;

	Matrix a, b, c, d;
	fin >> a >> b >> c;
	d = a * a + 2 * b - c;
	fout << d;
	return 0;
}