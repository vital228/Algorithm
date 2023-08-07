#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


void gen(vector<char>& sk, vector<char>& stack, int n, int k) {
	if (stack.size() == n-k) {
		for (int i = 0; i < k; i++) {
			cout << sk[i];
		}
		for (int i = stack.size()-1; i >= 0; i--) {
			cout << stack[i];
		}
		cout << endl;
	}
	else {
		sk[k] = '(';
		stack.push_back(')');
		gen(sk, stack, n, k + 1);
		stack.pop_back();
		sk[k] = '[';
		stack.push_back(']');
		gen(sk, stack, n, k + 1);
		stack.pop_back();
		if (k > 0 && stack.size()>0) {
			sk[k] = stack[stack.size() - 1];
			char c = sk[k];
			stack.pop_back();
			gen(sk, stack, n, k + 1);
			stack.push_back(c);
		}
	}
	
}

int main() {
	int n, m;
	cin >> n;
	vector<char> v(n);
	vector<char> k;
	gen(v, k, n, 0);
	return 0;
}