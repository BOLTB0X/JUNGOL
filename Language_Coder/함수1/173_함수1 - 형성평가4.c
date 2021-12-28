#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_answer(int a, int b) {
	if (a > b)
		printf("%d\n", a * a - b * b);
	else
		printf("%d\n", b * b - a * a);
	return;
}

void solution(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	print_answer(a, b);
	return;
}

int main(void) {
	solution();
	return 0;
}