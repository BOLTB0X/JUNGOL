#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int abs(int* a, int* b) {
	return *a - *b < 0 ? -(*a - *b) : *a - *b;
}

void solution(void) {
	int n, m, o, * p, * q, * r;
	p = &n;
	q = &m;
	r = &o;
	scanf("%d %d", p, q);

	r = abs(p, q);

	printf("%d\n", r);
	
	return;
}

int main(void) {
	solution();
	return 0;
}