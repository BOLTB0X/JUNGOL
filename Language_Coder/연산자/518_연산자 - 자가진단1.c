#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	printf("sum : %d\n", (a + b + c));
	printf("avg : %d\n", (a + b + c) / 3);

	return 0;
}