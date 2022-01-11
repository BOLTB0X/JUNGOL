#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int board[4][3] = {
	{3, 5, 9}, {2, 11, 5}, {8, 30, 10}, {22, 5, 1}
};

int main(void) {
	int tot = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d ", board[i][j]);
			tot += board[i][j];
		}
		printf("\n");
	}

	printf("%d", tot);

	return;
}