#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	
	printf("(%d - %d) ^ 2 = %d\n", a, b, (a - b) * (a - b));
	printf("(%d + %d) ^ 3 = %d\n", a, b, (a + b) * (a + b) * (a + b));

	return;
}

int main(void) {
	solution();

	return 0;
}