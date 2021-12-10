#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void solution(void) {
	int n, m; //높이 너비
	scanf("%d %d", &n, &m);

	int number = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", number++);
		}
		printf("\n");
	}

	return;
}

int main(void) {
	solution();
	return 0;
}