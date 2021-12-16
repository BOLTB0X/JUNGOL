#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char pane[101][101];

void fill_triangle(int n) {
	char alp = 'A';
	for (int i = 0; i < n; ++i) {
		for (int j = i, k = n - 1; j < n; ++j, --k) {
			pane[j][k] = alp++;
			if (alp > 'Z')
				alp = 'A';
		}
	}

	return;
}

void print_trianlge(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%c ", pane[i][j]);
		}
		printf("\n");
	}

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		memset(pane[i], ' ', sizeof(char) * n);

	fill_triangle(n);
	print_trianlge(n);

	return;
}

int main(void) {
	solution();
	return 0;
}