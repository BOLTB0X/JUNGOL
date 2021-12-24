#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a;
	printf("Number? ");
	scanf("%d", &a);

	if (a == 1)
		printf("dog\n");
	else if (a == 2)
		printf("cat\n");
	else if (a == 3)
		printf("chick\n");
	else
		printf("I don't know.\n");
	return 0;
}