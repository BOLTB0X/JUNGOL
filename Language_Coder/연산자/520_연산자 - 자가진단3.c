#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a;
	scanf("%d", &a);

	printf("%d\n", a++);
	printf("%d\n", ++a);

	return 0;
}