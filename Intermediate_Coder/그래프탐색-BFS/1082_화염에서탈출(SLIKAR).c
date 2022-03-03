#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MV 255555

typedef struct {
	int y, x, dist;
} Block;

Block que[MV];
int fr = 0, re = 0;

void enqueue(Block data) {
	que[re++] = data;
	return;
}

Block dequeue(void) {
	return que[fr++];
}

int n, m;
int visited[55][55];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

void process_Check(int y, int x, int sec) {
	//작다면 방문한것이므로 종료
	//무조건 커야함
	if (visited[y][x] <= sec)
		return;

	visited[y][x] = sec;
	//화염의 확산을 위해
	Block fire = { y,x,sec };
	enqueue(fire);
	return;
}

void BFS(int sy, int sx, int ey, int ex) {
	while (fr < re) {
		Block cur = dequeue();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			int ns = cur.dist + 1;

			process_Check(ny, nx, ns);
		}
	}
	return;
}

void solution(int sy, int sx, int ey, int ex) {
	//먼저 BFS탐색으로 불의 확산 시간들은 방문리스트에 남김
	visited[ey][ex] = 0; //불이 붙으면 안되므로
	BFS(sy, sx, ey, ex);

	fr = 0, re = 0;
	visited[ey][ex] = MV; // 진행자가 도달해야 하므로
	process_Check(sy, sx, 0);
	BFS(sy, sx, ey, ex);

	return;
}

int main(void) {
	char ch;
	int sy = 0, sx = 0, ey = 0, ex = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf(" %c", &ch);
			visited[i][j] = MV;

			if (ch == 'D')
				ey = i, ex = j;

			else if (ch == 'X')
				visited[i][j] = 0;

			else if (ch == 'S')
				sy = i, sx = j;

			else if (ch == '*')
				process_Check(i, j, 0);
		}
	}

	solution(sy, sx, ey, ex);

	if (visited[ey][ex] < MV)
		printf("%d", visited[ey][ex]);
	else
		printf("impossible");
	return 0;
}
