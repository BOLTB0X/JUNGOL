#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int board[31][31];

//파스칼식 채우기
void fill_triangle(int n) {
	//초기화
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			board[i][j] = 1;
	}

	for (int i = 2; i < n; ++i) {
		for (int j = 1; j < i; ++j) {
			board[i][j] = board[i - 1][j - 1] + board[i - 1][j];
		}
	}
	return;
}

//출력
void print_triangle(int n, int m) {
	if (m == 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) 
				printf("%d ", board[i][j]);
			printf("\n");
		}
	}

	else if (m == 2) {
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n - 1; ++j)
				printf(" ");
			for (int j = 0; j <= i; ++j)
				printf("%d ", board[i][j]);
			printf("\n");
		}
	}

	else {
		for (int i = n - 1; i >= 0; --i) {
			for (int j = n - 1; j >= i; --j)
				printf("%d ", board[j][i]);
			printf("\n");
		}
	}

	return;
}

void solution(int n, int m) {
	fill_triangle(n);
	print_triangle(n, m);
	return;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	solution(n, m);
	return 0;
}
