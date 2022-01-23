#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int board[101][101];
int visited[101][101];
int cnt = 0;
int answer[101];
int ans_idx = 0;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void DFS(int M, int N, int y, int x) {
	visited[y][x] = 1;
	cnt++;

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if (board[ny][nx] != 0 || visited[ny][nx] == 1)
			continue;
		DFS(M, N, ny, nx);
	}
	return;
}

void solution(void) {
	//M,NÁ¶½É
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < N; ++i) {
		memset(board[i], 0, sizeof(int) * M);
		memset(visited[i], 0, sizeof(int) * M);
	}

	for (int i = 0; i < K; ++i) {
		int y1, x1, y2, x2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

		for (int r = y1; r < y2; ++r) {
			for (int c = x1; c < x2; ++c)
				board[r][c] = 1;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == 0 && !visited[i][j]) {
				cnt = 0;
				DFS(M, N, i, j);
				if(cnt != 0)
					answer[ans_idx++] = cnt;
			}
		}
	}

	qsort(answer, ans_idx, sizeof(int), compare);

	printf("%d\n", ans_idx);
	for (int i = 0; i < ans_idx; ++i) {
		printf("%d ", answer[i]);
	}

	return;
}

int main(void) {
	solution();
	return 0;
}