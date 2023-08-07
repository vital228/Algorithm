#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

class Fractions {
	int n, m;
public:
	Fractions() {
		n = 0;
		m = 1;
	}

	Fractions(string s) {
		bool f = true;
		int i = 0;
		if (s[0]=='-') {
			f = false;
			i = 1;
		}
		n = s[i] - '0';
		i++;
		for (; s[i] != '/'; ++i) {
			n *= 10;
			n += s[i] - '0';
		}
		i++;
		m = s[i] - '0';
		i++;
		for (; i < s.size(); ++i) {
			m *= 10;
			m += s[i] - '0';
		}
		if (!f) {
			n *= -1;
		}
	}
	Fractions(const Fractions& f) {
		this->m = f.m;
		this->n = f.n;
	}
	int gcd(int a, int b) {
		if (a == 0 || b == 0) return a + b;
		return gcd(b % a, a);
	
	}

	Fractions& operator+(const Fractions& a) {		
		n = n * a.m + m * a.n;
		m *= a.m;
		if (n == 0) {
			m = 1;
		}
		else {
			int t = gcd(n, m);
			n /= t;
			m /= t;
		}
		return *this;
 	}
	Fractions& operator+=(const Fractions& a) {	
		return *this + a;
	}

	Fractions operator=(const Fractions& a) {
		m = a.m;
		n = a.n;
		return *this;
	}

	bool operator<(const Fractions& a) {
		return (long long)n*a.m<(long long)a.n*m;
	}
	bool operator<=(const Fractions& a) {
		return (long long)n * a.m <= (long long)a.n* m;
	}
	bool operator>(const Fractions& a) {
		return (long long)n * a.m > (long long)a.n * m;
	}
	bool operator>=(const Fractions& a) {
		return (long long)n * a.m >= (long long)a.n * m;
	}
	friend std::ostream& operator<< (std::ostream& out, const Fractions& a)
	{		
		out << a.n << '/' << a.m;
		return out;
	}
};


int binSearch(vector<Fractions> a, Fractions key) {  
	int l = -1;                    
	int r = a.size();
	while (l < r - 1) {             
		int m = (l + r) / 2;          
		if (a[m] <= key)
			l = m;
		else {
			r = m;                 
		}
	}
	return r;
}

int main() {
	int n;
	cin >> n;
	vector<Fractions> a;
	Fractions sum("0/1");
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		Fractions t(s);
		a.push_back(t);
		sum = sum + t;
	}
	cout << sum<<"\n";
	vector<Fractions> d(n+1);
	Fractions minf("-1000000/1");
	Fractions inf("1000000/1");
	d[0] = minf;
	int length = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}
	for (int i = 0; i < n; i++) {
		int j = binSearch(d, a[i]);
		if (d[j - 1] < a[i] && a[i] < d[j]) {
			d[j] = a[i];
			length = max(length, j);
		}
	}
	cout << length;
	return 0;
}