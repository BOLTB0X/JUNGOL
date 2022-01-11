#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int board[6][6] = { 0, };

int main(void) {
	for (int i = 1; i <= 5; i += 2) {
		board[1][i] = 1;
	}

	for (int i = 2; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
						
			board[i][j] = board[i - 1][j-1] + board[i - 1][j + 1];

		}
	}
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}


	return;
}