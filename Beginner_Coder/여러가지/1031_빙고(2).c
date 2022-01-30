#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int row_Check(int board[][5]) {
	int cnt = 0;
	int bingo = 0;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[i][j] == -1) {
				cnt++;

				if (cnt == 5)
					bingo++;
			}
		}
		cnt = 0;
	}
	return bingo;
}

int col_Check(int board[][5]) {
	int bingo = 0;
	int cnt = 0;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[j][i] == -1) {
				cnt++;

				if (cnt == 5)
					bingo++;
			}
		}
		cnt = 0;
	}
	return bingo;
}

int cross_Check(int board[][5]) {
	int cnt = 0;
	int bingo = 0;

	for (int i = 0; i < 5; ++i) {
		if (board[i][i] == -1) {
			cnt++;

			if (cnt == 5)
				bingo++;
		}
	}
	cnt = 0;
	for (int i = 4; i >= 0; --i) {
		if (board[5 - i - 1][i] == -1) {
			cnt++;

			if (cnt == 5)
				bingo++;
		}
	}
	return bingo;
}

void solution(int board[][5], int commend[][5]) {
	int cnt = 0;
	int tmp = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			int cmm = commend[i][j];

			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					if (cmm == board[i][j]) {
						board[i][j] = -1;
						cnt++;
						
						if (cnt >= 10) {
							tmp = row_Check(board) + col_Check(board) + cross_Check(board);
							if (tmp >= 3) {
								printf("%d", cnt);
								return;
							}
						}
						break;
					}
				}
			}
		}
	}
	return;
}

int main(void) {
	int board[5][5];
	int cmm[5][5];

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			scanf("%d", &board[i][j]);
	}
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			scanf("%d", &cmm[i][j]);
	}

	solution(board, cmm);
	return 0;
}