#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pane[100][100] = { 0, };

void fill_pane(int n, int m) {
	if (m == 1) {
		int number = 0;
		for (int i = 0; i < n; ++i) {
			//행이 바뀌기기 전
			number++;
			for (int j = 0; j < n; ++j) {
				pane[i][j] = number;
			}
		}
	}

	else if (m == 2) {
		for (int i = 0; i < n; ++i) {
			//분기
			if (i % 2 == 0) {
				int number = 1;
				for (int j = 0; j < n; ++j) 
					pane[i][j] = number++;
			}
			else {
				int number = n;
				for (int j = 0; j < n; ++j) 
					pane[i][j] = number--;
			}
		}
	}

	else {
		for (int i = 0; i < n; ++i) {
			int number = i + 1;
			for (int j = 0; j < n; ++j) {
				pane[i][j] = number;
				number += (i + 1);
			}
		}
	}

	return;
}

void print_pane(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", pane[i][j]);
		}
		printf("\n");
	}

	return;
}

void solution(void) {
	int n, m;

	scanf("%d %d", &n, &m);
	fill_pane(n, m);
	print_pane(n);

	return;
}

int main(void) {
	solution();
	return 0;
}
