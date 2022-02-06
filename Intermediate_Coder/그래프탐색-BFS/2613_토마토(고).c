#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int y, x, day;
} TOMATO;

int board[1001][1001];
TOMATO* que;
int head = 0, tail = 0;

//상하좌우
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

//push
void enqueue(int size, TOMATO data) {
	que[tail++] = data;
	tail = tail % size;
	return;
}

//pop
void dequeue(int size) {
	head++;
	head = head % size;
	return;
}

//범우 내
int in_Range(int y, int x, int m, int n) {
	return 0 <= y && 0 <= x && y < n && x < m;
}

int solution(int m, int n) {
	int answer = 0;
	int size = m * n + 1;

	que = (TOMATO*)malloc(sizeof(TOMATO) * size);

	//토마토 위치 찾기
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1) {
				TOMATO tmp = { i,j, 0 };
				enqueue(size, tmp);
			}
		}
	}

	//BFS탐색
	while (head != tail) {
		TOMATO cur = que[head];
		dequeue(size);

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//범위내, 안익은 토마토이면
			if (in_Range(ny, nx, m, n) && board[ny][nx] == 0) {
				board[ny][nx] = 1;
				answer = cur.day + 1;
				TOMATO next = { ny, nx, cur.day + 1 };
				enqueue(size, next);
			}
		}
	}

	//안익은 토마토 검사
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0)
				return -1;
		}
	}

	return answer;
}

int main(void) {
	int m, n;
	
	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);
	}

	int ret = solution(m, n);
	printf("%d", ret);

	return 0;
}
