#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ML 101

int cheese_cnt = 0;
int board[ML][ML];
int visited[ML][ML];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

void init(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			visited[i][j] = 0;
	}
	return;
}

//깊이우선탐색
//겉 테두리 공기화될 대상 체크
void DFS(int n, int m, int y, int x) {
	//어차피 첫 가장자리는 무조건 0
	if (board[y][x] == 1) {
		cheese_cnt--;
		board[y][x] = 0; //녹음
		visited[y][x] = 1;
		return;
	}

	//미방문인 경우
	else if (visited[y][x] == 0) {
		visited[y][x] = 1;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (visited[ny][nx] == 1)
				continue;

			DFS(n, m, ny, nx);
		}
	}
	return;
}

void solution(int n, int m) {
	int cnt = 0, r_cnt = 0;

	while (cheese_cnt != 0) {
		init(n, m);
		cnt++;
		r_cnt = cheese_cnt;
		
		//공기로 녹이기 시작
		DFS(n, m, 0, 0);
	}

	printf("%d\n", cnt);
	printf("%d\n", r_cnt);
	return;
}

int main(void) {
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &board[i][j]);

			if (board[i][j] == 1)
				cheese_cnt++;
		}
	}
	
	solution(n, m);

	return 0;
}
