#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int board[13];
int result = 0;

int abs(int a) {
	return a < 0 ? -a : a;
}

int is_promising(int row) {
	// 같은 열이면 X, 대각선상에 있어서도 X
	for (int i = 0; i < row; i++) {
		//행 차이 =  열차이 = 같은 대각선 상
		if (board[row] == board[i] || row - i == abs(board[row] - board[i]))
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