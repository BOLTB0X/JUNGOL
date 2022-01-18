#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, tot = 0;
	scanf("%d %d", &a, &b);

	for (int i = a; i <= b; ++i)
		tot += i;

	printf("%d", tot);
	return 0;
}