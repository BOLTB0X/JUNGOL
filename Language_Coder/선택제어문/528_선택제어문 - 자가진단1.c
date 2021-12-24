#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	printf("%d\n", n);
	if (n < 0)
		printf("minus\n");

	return 0;
}