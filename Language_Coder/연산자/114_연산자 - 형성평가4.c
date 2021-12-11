#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	++a;
	printf("%d %d\n", a, b);
	b--;
	printf("%d %d\n", a, b);

	return 0;
}