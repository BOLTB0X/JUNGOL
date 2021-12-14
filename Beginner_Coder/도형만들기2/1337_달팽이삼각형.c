#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int pane[100][100];
//¥ﬁ∆ÿ¿Ã πÊ«‚
const int dy[3] = { 1,0,-1 };
const int dx[3] = { 1,-1,0 };

bool in_Range(int sy, int sx, int n) {
	return 0 <= sy && sy < n && 0 <= sx && sx < n;
}

void init_pane(int n) {
	for (int i = 0; i < n; ++i)
		memset(pane[i], -1, sizeof(int) * n);
	return;
}

void print_pane(int n) {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x <= y; ++x)
			printf("%d ", pane[y][x]);
		printf("\n");
	}

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	init_pane(n);

	int cy = 0, cx = 0;
	int number = 0;

	while (in_Range(cy,cx,n) && pane[cy][cx] == -1) {
		for (int dir = 0; dir < 3; ++dir) {
			if (!in_Range(cy, cx, n) || pane[cy][cx] != -1)
				break;

			while (true) {
				pane[cy][cx] = number % 10;
				number++;
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];

				if (!in_Range(ny, nx, n) || pane[ny][nx] != -1) {
					cy += dy[(dir + 1) % 3];
					cx += dx[(dir + 1) % 3];
					break;
				}

				cy = ny;
				cx = nx;
			}
		}
	}

	print_pane(n);
	return;
}

int main(void) {
	solution();
	return 0;
}