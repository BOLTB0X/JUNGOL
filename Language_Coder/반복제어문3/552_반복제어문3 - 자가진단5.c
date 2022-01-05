#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int n;
	scanf("%d", &n);

	for (int i = n; i >= 1; --i) {
		for (int j = n; j > i; --j)
			printf(" ");
		for (int j = 1; j <= 2 * i - 1; ++j)
			printf("*");
		printf("\n");
	}

	return;
}

int main(void) {
	solution();
	return 0;
}