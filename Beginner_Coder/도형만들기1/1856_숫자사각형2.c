#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pane[100][100] = { 0, };

void fill_Pane(int n, int m) {
	int number = 1;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; ++j) 
				pane[i][j] = number++;
		}
		else {
			for (int j = m - 1; j >= 0; --j)
				pane[i][j] = number++;
		}
	}

	return;
}

void print_Pane(n, m) {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			printf("%d ", pane[y][x]);
		}
		printf("\n");
	}

	return;
}

void solution(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	fill_Pane(n, m);

	print_Pane(n, m);

	return;
}

int main(void) {
	solution();
	return 0;
}