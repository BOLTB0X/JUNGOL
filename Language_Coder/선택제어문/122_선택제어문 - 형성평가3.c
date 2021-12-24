#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a;
	scanf("%d", &a);

	if ((a % 400) == 0 || (a%4 == 0 && a%100 != 0))
		printf("leap year\n");
	else
		printf("common year\n");
	return 0;
}