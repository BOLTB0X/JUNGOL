#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pane[100][100] = { 0, };

void fill_pane(int n) {
	int number = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			pane[j][i] = number++;
		}
	}

	return;
}

void print_pane(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ",pane[i][j]);
		}
		printf("\n");
	}

	return;
}

void solution(void) {
	int n;

	scanf("%d", &n);
	fill_pane(n);
	print_pane(n);

	return;
}

int main(void) {
	solution();
	return 0;
}