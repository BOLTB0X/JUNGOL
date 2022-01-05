#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int n;
	scanf("%d", &n);

	for (int i = n; i > 0; --i) {
		for (int j = i; j < n; ++j)
			printf(" ");
		for (int j = 0; j < i; ++j)
			printf("*");
		printf("\n");
	}

	return;
}

int main(void) {
	solution();
	return 0;
}