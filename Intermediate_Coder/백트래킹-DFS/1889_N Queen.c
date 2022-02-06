#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int board[13];
int result = 0;

int abs(int a) {
	return a < 0 ? -a : a;
}

int is_promising(int row) {
	for (int col = 0; col < row; ++col) {
		//같은 열 또는 대각선 상
		if (board[row] == board[col] || row - col == abs(board[row] - board[col]))
			return 0;
	}
	return 1;
}

void N_Queen(int row) {
	if (row == n) {
		result++;
		return;
	}

	for (int col = 0; col < n; ++col) {
		board[row] = col;
		if (is_promising(row)) {
			N_Queen(row + 1);
		}
	}

	return;
}

int main(void) {
	scanf("%d", &n);

	N_Queen(0);

	printf("%d", result);
	return 0;
}
