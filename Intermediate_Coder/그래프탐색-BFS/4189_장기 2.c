#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MS 1001

typedef struct {
	int y, x, dist;
} Pos;

Pos que[MS * MS];
int fr = 0, re = 0;

void enqueue(Pos data) {
	que[re++] = data;
	return;
}

Pos dequeue(void) {
	return que[fr++];
}

int visited[MS][MS];

const int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int BFS(int n, int m, int sy, int sx, int ey, int ex) {
	int result = 0;
	Pos start = { sy, sx, 0 };
	enqueue(start);
	visited[sy][sx] = 1;

	while (fr < re) {
		Pos cur = dequeue();

		//잡았다면
		if (cur.y == ey && cur.x == ex)
			return cur.dist;

		for (int dir = 0; dir < 8; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//범위초과
			if (ny < 1 || nx < 1 || ny > n || nx > m)
				continue;

			//재방문
			if (visited[ny][nx] == 1)
				continue;

			result = cur.dist + 1;
			visited[ny][nx] = 1;
			Pos next = { ny, nx, cur.dist + 1 };
			enqueue(next);
		}
	}
}

int solution(int n, int m, int sy, int sx, int ey, int ex) {
	int answer = 0;

	//초기화
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j)
			visited[i][j] = 0;
	}

	answer = BFS(n, m, sy, sx, ey, ex);

	return answer;
}

int main(void) {
	int n, m;
	int sy, sx, ey, ex;

	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &sy, &sx, &ey, &ex);

	int ret = solution(n, m, sy, sx, ey, ex);
	printf("%d", ret);
	return 0;
}