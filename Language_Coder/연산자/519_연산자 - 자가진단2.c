#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

	int result1 = a + 100;
	int result2 = b % 10;

	printf("%d\n", result1);
	printf("%d\n", result2);

	return 0;
}