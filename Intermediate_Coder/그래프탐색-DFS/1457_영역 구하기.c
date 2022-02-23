#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ML 101*101

int board[101][101];
int visited[101][101];

int result[ML], r_idx = 0, cnt = 0;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

//초기화
void init(int m, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			visited[i][j] = 0;
	}

	return;
}

void DFS(int m, int n, int y, int x) {
	visited[y][x] = 1;
	cnt++;

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (0 <= ny && ny < n && 0 <= nx && nx < m) {
			if (visited[ny][nx] == 0 && board[ny][nx] == 0)
				DFS(m, n, ny, nx);
		}
	}
	return;
}

void solution(int m, int n) {
	init(m, n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0 && visited[i][j] == 0) {
				cnt = 0;
				DFS(m, n, i, j);
				result[r_idx++] = cnt;
			}
		}
	}

	qsort(result, r_idx, sizeof(int), compare);
	return;
}

int main(void) {
	int m, n, k;
	int y1, x1, y2, x2;

	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		for (int y = y1; y < y2; ++y) {
			for (int x = x1; x < x2; ++x)
				board[y][x] = 1;
		}
	}

	solution(m, n);

	printf("%d\n", r_idx);
	for (int i = 0; i < r_idx; ++i)
		printf("%d ", result[i]);
	return 0;
}
