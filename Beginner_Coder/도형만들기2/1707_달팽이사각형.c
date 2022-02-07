#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int pane[100][100];
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };

bool in_Range(int cy, int cx, int n) {
	return 0 <= cy && cy < n && 0 <= cx && cx < n;
}

void fill_pane(int n) {
	int number = 1;
	int cy = 0, cx = 0;

	while (in_Range(cy,cx,n) && pane[cy][cx] == 0) {
		for (int dir = 0; dir < 4; ++dir) {
			if (!in_Range(cy, cx, n) || pane[cy][cx] != 0)
				break;

			while (1) {
				pane[cy][cx] = number++;
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];

				if (!in_Range(ny, nx, n) || pane[ny][nx] != 0) {
					cy += dy[(dir + 1) % 4];
					cx += dx[(dir + 1) % 4];
					break;
				}

				cy = ny;
				cx = nx;
			}
		}
	}

	return;
}

int print_pane(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			printf("%d ", pane[i][j]);
		printf("\n");
	}
}

void solution(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) 
		memset(pane[i], 0, sizeof(int) * n);
	

	fill_pane(n);
	print_pane(n);

	return;
}

int main(void) {
	solution();
	return 0;
}
