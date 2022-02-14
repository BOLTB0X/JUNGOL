#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int y, x, dist;
} NODE;

NODE que[25110];
int head = 0, tail = 0;

void enqueue(NODE data) {
	que[tail++] = data;
	return;
}

NODE dequeue(void) {
	return que[head++];
}

int r, c;
int visited[55][55];

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

void check(int y, int x, int sec) {
	if (visited[y][x] <= sec)
		return;
	visited[y][x] = sec;
	NODE fire = { y,x, sec };
	enqueue(fire);
	return;
}

void BFS(int sy, int sx, int ey, int ex) {
	while (head < tail) {
		NODE cur = dequeue();
		for (int dir = 0; dir < 4; ++dir) {
			check(cur.y + dy[dir], cur.x + dx[dir], cur.dist + 1);
		}
	}

	return;
}

void solution(int sy, int sx, int ey, int ex) {
	//BFS 너비우선 탐색
	//빈칸 . ,불 '*', 바위 'X', 용사의 집 'D', 스타트 'S'

	//불을 시간별로 지핌
	visited[ey][ex] = 0;
	BFS(sy, sx, ey, ex);
	
	//이제 용사 차례
	head = 0, tail = 0;
	visited[ey][ex] = 255110;
	check(sy, sx, 0);
	BFS(sy, sx, ey, ex);

	return;
}

int main(void) {
	char ch;
	int sy = 0, sx = 0, ey = 0, ex = 0;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			scanf(" %c", &ch);

			visited[i][j] = 255110;

			if (ch == 'X')
				visited[i][j] = 0;
			else if (ch == '*')
				check(i, j, 0);
			else if (ch == 'S')
				sy = i, sx = j;
			else if (ch == 'D')
				ey = i, ex = j;
		}
	}
	
	solution(sy, sx, ey, ex);

	if (visited[ey][ex] < 255110)
		printf("%d", visited[ey][ex]);
	else
		printf("impossible");

	return 0;
}