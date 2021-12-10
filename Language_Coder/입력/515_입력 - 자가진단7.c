#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d * %d = %d\n", a, b, (int)a * b);
	printf("%d / %d = %d\n", a, b, (int)a / b);

	return 0;
}