#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int abs(int a) {
	return a < 0 ? -a : a;
}

int main(void) {
	char c1, c2;
	scanf("%c %c", &c1, &c2);

	printf("%d %d\n", c1 + c2, abs(c1 - c2));
	return 0;
}