#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void triangle_type(int h) {
	for (int i = 0; i < h / 2; ++i) {
		for (int j = 0; j < i; ++j)
			printf(" ");
		for (int j = 0; j < 2 * i + 1; ++j)
			printf("*");
		printf("\n");
	}

	for (int i = 0; i < h / 2 + 1; ++i) {
		for (int j = 0; j < h / 2 - i; ++j)
			printf(" ");
		for (int j = 0; j < h - 2 * i; ++j)
			printf("*");
		printf("\n");
	}
	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	if (n <= 0 || n > 100 || n % 2 == 0)
		printf("INPUT ERROR!\n");
	else
		triangle_type(n);

	return;
}

int main(void) {
	solution();
	return 0;
}