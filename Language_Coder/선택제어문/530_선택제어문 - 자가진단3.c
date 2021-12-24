#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int old;
	scanf("%d", &old);

	if (old >= 20)
		printf("adult\n");
	else
		printf("%d years later\n", 20 - old);
	return 0;
}