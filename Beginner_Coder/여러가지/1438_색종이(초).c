#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pane[100][100];

void fill_pane(int x, int y) {
	for (int i = y; i < y + 10; ++i) {
		for (int j = x; j < x + 10; ++j) 
			pane[i][j] = 1;
	}

	return;
}

int get_area(void) {
	int tot = 0;

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (pane[i][j] == 1)
				tot += 1;
		}
	}

	return tot;
}

void solution(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		fill_pane(x, y);
	}

	printf("%d", get_area());
	return;
}

int main(void) {
	solution();
	return 0;
}