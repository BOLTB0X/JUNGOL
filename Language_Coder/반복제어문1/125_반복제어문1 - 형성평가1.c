#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num;
	scanf("%d", &num);

	int start = 1;
	while (start <= num) 
		printf("%d ",start++);

	return 0;
}