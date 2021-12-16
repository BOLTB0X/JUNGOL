#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char pane[101][101];

void fill_triangle(int n) {
	for (int i = 0; i <= n; ++i)
		memset(pane[i], 0, sizeof(char) * (n + 1));

	char alp = 'A';
	for (int i = n / 2; i >= 0; --i) {
		for (int j = i; j < n - i; ++j) {
			pane[j][i] = alp++;

			if (alp > 'Z')
				alp = 'A';
		}
	}

	return;
}

void print_trianlge(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (pane[i][j] == 0)
				printf(" ");
			else
				printf("%c ", pane[i][j]);
		}
		printf("\n");
	}

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	if (n < 1 || n > 101 || n % 2 == 0)
		printf("INPUT ERROR\n");
	else {
		fill_triangle(n);
		print_trianlge(n);
	}
	return;
}

int main(void) {
	solution();
	return 0;
}