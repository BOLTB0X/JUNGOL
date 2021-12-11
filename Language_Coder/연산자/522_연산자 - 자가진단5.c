#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	int res = a == b ? 1 : 0;
	printf("%d\n",res);
	if (res == 1)
		printf("0\n");
	else
		printf("1\n");
	return 0;
}