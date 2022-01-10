#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int board[101][101];

void fill(int n) {
	int num = 1;
	int m = n;
	int y = 1, x = 0;

	while (m > 0) {
		// - >
		for (int i = 1; i <= m; ++i) {
			x++;
			board[y][x] = num++;
		}
		m--;

		// ¾Æ·¡
		for (int i = 1; i <= m; ++i) {
			y++;
			board[y][x] = num++;
		}
		
		// <-
		for (int i = 1; i <= m; ++i) {
			x--;
			board[y][x] = num++;
		}
		m--;

		//À§
		for (int i = 1; i <= m; ++i) {
			y--;
			board[y][x] = num++;
		}
	}
}

void print_board(n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			printf("%d ", board[i][j]);
		printf("\n");
	}

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	fill(n);
	print_board(n);
}

int main(void) {
	solution();
	return 0;
}