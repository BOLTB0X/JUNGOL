#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int n;
	scanf("%d", &n);

	int num = 1;
	char alp = 'A';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) 
			printf("%d ", num++);
		for (int j = 0; j <= i; ++j)
			printf("%c ", alp++);
		printf("\n");
	}

	return;
}

int main(void) {
	solution();
	return 0;
}