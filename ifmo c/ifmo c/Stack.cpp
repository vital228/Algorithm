#include <iostream>
#include <fstream>
#include<string>
#include<cstring>
using namespace std;
struct Stack {
	int tail = 0;
	int arr[1000000];
};
void Push_Stack(Stack* a, int x) {
	a->arr[a->tail] = x;
	a->tail++;
}
void Pop_Stack(Stack* a) {
	a->arr[a->tail - 1] = 0;
	a->tail--;
}
int Get_Stack(Stack* a) {
	return a->arr[a->tail - 1];
}
bool Is_Empty_Stack(Stack* a) {
	return a->tail==0;
}

int main() {
	int n;
	ifstream fin("postfix.in");
	ofstream fout("postfix.out");
	string s,s1;
	Stack a;
	//while (fin >> s1) {
	//	s += s1;
	//}
	getline(fin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int k = 0;
			while (s[i] != ' ') {
				k = k * 10 + int(s[i]) - '0';
				i++;
			}
			Push_Stack(&a, k);
		}
		else {
			if (s[i] == '+') {
				int n1 = Get_Stack(&a);
				Pop_Stack(&a);
				int n2 = Get_Stack(&a);
				Pop_Stack(&a);
				n1 += n2;
				Push_Stack(&a,n1);
			}
			if (s[i] == '*') {
				int n1 = Get_Stack(&a);
				Pop_Stack(&a);
				int n2 = Get_Stack(&a);
				Pop_Stack(&a);
				n1 *= n2;
				Push_Stack(&a,n1);
			}
			if (s[i] == '-') {
				int n1 = Get_Stack(&a);
				Pop_Stack(&a);
				int n2 = Get_Stack(&a);
				Pop_Stack(&a);
				n2 -= n1;
				Push_Stack(&a,n2);
			}
		}
	}
	fout << Get_Stack(&a);
	fin.close();
	fout.close();
	return 0;
}