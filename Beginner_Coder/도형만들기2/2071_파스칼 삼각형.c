#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int pane[30][30];

void fill_pane(n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			pane[i][j] = 1;

	for (int i = 2; i < n; ++i) {
		for (int j = 1; j < i; ++j)
			pane[i][j] = pane[i - 1][j] + pane[i - 1][j - 1];
	}

	return;
}

void print_pane(int n, int m) {
	if (m == 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) 
				printf("%d ", pane[i][j]);
			printf("\n");
		}
	}

	else if (m == 2) {
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < n-i-1; ++j)
				printf(" ");
			for (int j = 0; j <= i; ++j)
				printf("%d ", pane[i][j]);
			printf("\n");
		}
	}
	
	else if (m == 3) {
		for (int i = 0; i < n; ++i) {
			for (int j = n-1; j >= n- i - 1; --j)
				printf("%d ", pane[j][n-i-1]);
			printf("\n");
		}
	}

	return;
}

void solution(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	fill_pane(n);
	

	print_pane(n, m);
	return;
}

int main(void) {
	solution();
	return 0;
}