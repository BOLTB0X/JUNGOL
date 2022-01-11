#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int board[4][3] = {0,};

int main(void) {
	int tot = 0;
	for (int i = 0; i < 4; ++i) {
		printf("%dclass? ", i + 1);
		scanf("%d %d %d", &board[i][0], &board[i][1], &board[i][2]);
	}

	for (int i = 0; i < 4; ++i) {
		printf("%dclass : %d\n", i + 1, board[i][0] + board[i][1] + board[i][2]);
	}

	return;
}