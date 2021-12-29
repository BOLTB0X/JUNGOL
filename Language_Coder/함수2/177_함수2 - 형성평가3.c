#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int get_sum(int a, int b, int c, int d, int e) {
	return abs(a) + abs(b) + abs(c) + abs(d) + abs(e);
}

void solution(void) {
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	printf("%d\n", get_sum(a, b, c, d, e));

	return;
}

int main(void) {
	solution();

	return 0;
}