#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int pane[100][100];

void fill_sq(int n) {
	int number = 1;
	int cy = 0, cx = 0;
	int tmp = 0;
	pane[cy][cx] = number;

	while (tmp < n-1) {
		if (tmp % 2 == 0) {
			pane[++cy][cx] = ++number;
			tmp++;

			for (int i = 0; i < tmp; ++i)
				pane[--cy][++cx] = ++number;
		}

		else {
			pane[cy][++cx] = ++number;
			tmp++;

			for (int i = 0; i < tmp; ++i)
				pane[++cy][--cx] = ++number;
		}
	}
	
	while (tmp > 0) {
		if (tmp % 2 == 0) {
			pane[cy][++cx] = ++number;
			tmp--;

			for (int i = 0; i < tmp; ++i)
				pane[--cy][++cx] = ++number;
		}

		else {
			pane[++cy][cx] = ++number;
			tmp--;

			for (int i = 0; i < tmp; ++i)
				pane[++cy][--cx] = ++number;
		}
	}

	return;
}

void print_sq(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%d ", pane[i][j]);
		printf("\n");
	}

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);
	
	fill_sq(n);

	print_sq(n);
	return;
}

int main(void) {
	solution();
	return 0;
}