#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int y, x, day;
} JUGGLE;

JUGGLE que[10201];
int head = 0, tail = 0;

void enqueue(JUGGLE data) {
	que[tail++] = data;
	return;
}

JUGGLE dequeue(void) {
	return que[head++];
}

int n, m;
int board[101][101];
int visited[101][101];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

int BFS(int x, int y) {
	int result = 0;

	JUGGLE start = { y, x, 0 };
	enqueue(start);
	visited[y][x] = 1;

	while (head != tail) {
		JUGGLE cur = dequeue();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (ny <1 || ny > m || nx < 1 || nx > n)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			if (board[ny][nx] == 1) {
				result = cur.day + 1;
				visited[ny][nx] = 1;
				JUGGLE next = { ny, nx, cur.day + 1 };
				enqueue(next);
			}
		}
	}

	return result;
}

void solution(int jx, int jy) {
	int sec = BFS(jx, jy);

	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (visited[i][j] == 0 && board[i][j] == 1)
				cnt++;
		}
	}

	printf("%d\n", sec + 3);
	printf("%d", cnt);

	return;
}

int main(void) {
	int jx, jy;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) 
			scanf("%1d", &board[i][j]);
	}

	for (int i = 0; i <= m; ++i) 
		memset(visited[i], 0, sizeof(int) * (n + 1));
	
	scanf("%d %d", &jx, &jy);
	solution(jx, jy);
	return 0;
}