#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("sum %d\n", a + b + c + d);
	printf("avg %d\n", (a + b + c + d) / 4);

	return 0;
}