#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b,c;
	scanf("%d %d %d", &a, &b, &c);

	printf("%d %d\n", a > b && a > c, a == b && b == c);

	return 0;
}