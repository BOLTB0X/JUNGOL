#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MV 255555

typedef struct {
	int y, x, sec;
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

int visited[51][51];
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

//사전 체크
void prepare_Process(int y, int x, int sec) {
	//재방문 방지
	if (visited[y][x] <= sec)
		return;
	
	visited[y][x] = sec;
	Block pos = { y, x, sec };
	enqueue(pos);

	return;
}

//너비우선 탐색
void BFS(int n, int m) {
	while (fr < re) {
		Block cur = dequeue();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			int nd = cur.sec + 1;

			//범위 밖인 경우
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			prepare_Process(ny, nx, nd);
		}
	}
}

void solution(int n, int m, int sy, int sx, int ey, int ex) {
	//화염먼저 진행
	visited[ey][ex] = 0; // 목적지에는 불이 안 붙음
	BFS(n, m); //먼저 BFS탐색으로 불의 확산 시간들은 방문리스트에 남김

	//이제 용사 진행
	visited[ey][ex] = MV; //목적지에 가야하므로
	prepare_Process(sy, sx, 0);
	BFS(n, m); //먼저 BFS탐색으로 용사 진행 시간들은 방문리스트에 남김

	return;
}

int main(void) {
	int n, m;
	int sy = 0, sx = 0, ey = 0, ex = 0;
	char ch;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf(" %c", &ch);
			visited[i][j] = MV;

			if (ch == 'S') //출발
				sy = i, sx = j;

			else if (ch == 'D') //목적기
				ey = i, ex = j;

			else if (ch == '*') //불
				prepare_Process(i, j, 0);

			else if (ch == 'X') //바위
				visited[i][j] = 0;
		}
	}

	solution(n, m, sy, sx, ey, ex);
	
	//출력
	if (visited[ey][ex] < MV)
		printf("%d", visited[ey][ex]);
	else
		printf("impossible");
	return 0;
}
