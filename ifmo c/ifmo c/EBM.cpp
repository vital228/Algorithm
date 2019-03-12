#include<stdio.h>

using namespace std;

int main() {
	short a1, a2;
	scanf("%x %x", &a1, &a2);
	printf("%#x %#x", (3 * a1 + 3) / 8, -(5 * a2 + 7) / 2);
}