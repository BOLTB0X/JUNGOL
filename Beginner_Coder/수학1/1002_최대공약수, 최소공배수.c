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
	int n;
	int arr[10];
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	int ret1 = arr[0];
	int ret2 = arr[0];

	for (int i = 1; i < n; ++i) {
		ret1 = gcd(ret1, arr[i]);
		ret2 = lcm(ret2, arr[i]);
	}
	printf("%d %d\n", ret1, ret2);
	return 0;
}
