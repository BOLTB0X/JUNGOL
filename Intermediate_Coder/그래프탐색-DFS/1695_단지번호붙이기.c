#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int board[25][25];
int visited[25][25];

int result[25];
int result_idx = 0;
int apart_cnt = 0;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void insert_Sort(void) {
	for (int i = 1; i < result_idx; ++i) {
		for (int j = i; j > 0; --j) {
			if (result[j] < result[j - 1])
				swap(&result[j], &result[j - 1]);
		}
	}
	return;
}

void DFS(int n, int y, int x) {
	visited[y][x] = 1;
	apart_cnt++;
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (0 > ny || ny >= n || 0 > nx || nx >= n)
			continue;

		if (visited[ny][nx] == 1 || board[ny][nx] == 0)
			continue;

		DFS(n, ny, nx);
	}

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &board[i][j]);
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j] && board[i][j] == 1) {
				apart_cnt = 0;
				DFS(n, i, j);
				result[result_idx++] = apart_cnt;
			}
		}
	}

	printf("%d\n", result_idx);
	if (result_idx > 1)
		insert_Sort();
	for (int i = 0; i < result_idx; ++i)
		printf("%d\n", result[i]);

	return;
}

int main(void) {
	solution();

	return 0;
}
