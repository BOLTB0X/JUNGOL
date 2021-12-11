#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d > %d --- %d\n", a, b, a > b ? 1 : 0);
	printf("%d < %d --- %d\n", a, b, a < b ? 1 : 0);
	printf("%d >= %d --- %d\n", a, b, a >= b ? 1 : 0);
	printf("%d <= %d --- %d\n", a, b, a <= b ? 1 : 0);
	return 0;
}