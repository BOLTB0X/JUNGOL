#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int* ptr;
	ptr = &n;

	scanf("%d", &n);

	int div = *ptr / 10;
	int rest = *ptr % 10;

	printf("%d...%d\n", div, rest);

	return 0;
}