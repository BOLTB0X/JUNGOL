#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n,m;
	int* ptr1, *ptr2;
	ptr1 = &n;
	ptr2 = &m;

	scanf("%d %d", &n, &m);

	printf("%d + %d = %d\n", n, m, *ptr1 + *ptr2);
	printf("%d - %d = %d\n", n, m, *ptr1 - *ptr2);
	printf("%d * %d = %d\n", n, m, *ptr1 * *ptr2);
	printf("%d / %d = %d\n", n, m, (int)*ptr1  / *ptr2);

	return 0;
}