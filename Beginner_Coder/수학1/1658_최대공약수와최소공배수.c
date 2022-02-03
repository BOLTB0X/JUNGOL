#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//최대공약수
int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

//최소공배수
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	int ret1 = gcd(n, m);
	int ret2 = lcm(n, m);

	printf("%d\n", ret1);
	printf("%d\n", ret2);
	return 0;
}
