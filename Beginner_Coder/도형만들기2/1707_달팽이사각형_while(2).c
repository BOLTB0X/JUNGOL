#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int board[101][101];

void fill(int n) {
	int num = 1;
	int m = n;
	int y = 1, x = 0;

	//�� �׵θ��� 1�� �ʱ�ȭ
	for (int i = 0; i <= n + 1; ++i) {
		board[0][i] = board[n + 1][i] = 1;
		board[i][0] = board[i][n + 1] = 1;
	}

	while (num <= n*n) {
		//������
		while (board[y][x + 1] == 0) {
			x++;
			board[y][x] = num++;
		}
		
		//�Ʒ�
		while (board[y+1][x] == 0) {
			y++;
			board[y][x] = num++;
		}
		
		//����
		while (board[y][x-1] == 0) {
			x--;
			board[y][x] = num++;
		}
		
		//����
		while (board[y-1][x] == 0) {
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