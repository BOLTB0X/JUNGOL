#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int row_Check(int (*board)[5]) {
	int tmp = 0;
	int bingo = 0;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[i][j] == 0)
				tmp++;
				if (tmp == 5)
					bingo++;
		}
		tmp = 0;
	}
	return bingo;
}

int col_Check(int (*board)[5]) {
	int tmp = 0;
	int bingo = 0;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[j][i] == 0)
				tmp++;
				if (tmp == 5)
					bingo++;
		}
		tmp = 0;
	}
	return bingo;
}

int cross_Check(int (*board)[5]) {
	int tmp = 0;
	int bingo = 0;

	for (int i = 0; i < 5; ++i) {
		if (board[i][i] == 0) {
			tmp++;
			if (tmp == 5)
				bingo++;
		}
	}

	tmp = 0;
	for (int i = 0; i < 5; ++i) {
		if (board[5 -i - 1][i] == 0) {
			tmp++;
			if (tmp == 5)
				bingo++;
		}
	}

	return bingo;
}

void solution(void) {
	int board[5][5];
	int commend[5][5];

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			scanf("%d", &board[i][j]);
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			scanf("%d", &commend[i][j]);
	}

	int cnt = 0;
	int row = 0, col = 0;
	//½Ã¹Ä½ÃÀÛ
	while (cnt < 25) {
		cnt++;

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (board[i][j] == commend[row][col])
					board[i][j] = 0;
			}
		}

		int cmp = row_Check(board) + col_Check(board) + cross_Check(board);
		if (cmp >= 3) {
			printf("%d", cnt);
			return;
		}

		col++;
		if (col == 5) {
			col = 0;
			row++;
		}
	}
	return;
}

int main(void) {
	solution();

	return 0;
}