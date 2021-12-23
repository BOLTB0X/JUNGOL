#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int *n;
	double *m;

	printf("%p %p", &n, &m);
	return;
}

int main(void) {
	solution();
	return 0;
}