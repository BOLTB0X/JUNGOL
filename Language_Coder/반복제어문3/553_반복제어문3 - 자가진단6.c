#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int n;
	scanf("%d", &n);

	char alp = 'A';
	for (int i =0; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			printf("%c", alp++);
		}
		printf("\n");
	}

	return;
}

int main(void) {
	solution();
	return 0;
}