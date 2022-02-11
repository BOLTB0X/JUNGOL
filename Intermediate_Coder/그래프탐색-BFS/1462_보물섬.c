#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int y, x, dist;
}NODE;

NODE que[2501];
int head = 0, tail = 0;

int n, m, result = -1;
char board[50][50];
int visited[50][50];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

void enqueue(NODE data) {
	que[tail++] = data;
	return;
}

NODE dequeue(void) {
	return que[head++];
}

int max(int a, int b) {
	return a > b ? a : b;
}

void init(void) {
	head = 0, tail = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = 0x7fffffff;
		}
	}
	return;
}

void BFS(int y, int x) {
	init();
	NODE start = { y,x,0 };
	enqueue(start);
	visited[y][x] = 0;

	while (head != tail) {
		NODE cur = dequeue();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//범위 초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			//바다
			if (board[ny][nx] == 'W')
				continue;
			int next_dist = cur.dist + 1;
			//재방문 방지
			if (visited[ny][nx] <= next_dist)
				continue;

			visited[ny][nx] = next_dist;
			NODE next = { ny, nx, next_dist };
			enqueue(next);
		}
	}
	
	//이번 BFS탐색으로 최단 거리 구함
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visited[i][j] != 0x7fffffff)
				result = max(result, visited[i][j]);
		}
	}
	return;
}

void solution(void) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'L')
				BFS(i, j);
		}
	}
	
	
	
	printf("%d", result);
	return;
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%s", board[i]);
	}

	solution();
	return 0;
}