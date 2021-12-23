#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int n, * p;
	p = &n;
	scanf("%d", p);
	
	for (int i = 0; i < *p; ++i)
		printf("*");
	return;
}

int main(void) {
	solution();
	return 0;
}