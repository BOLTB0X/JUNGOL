#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MS 1000001 //최대 사이즈

typedef struct {
	int y, x, z, dist;
} Block;

Block que[MS];
int fr = 0, re = 0;

void enqueue(Block data) {
	que[re++] = data;
	return;
}

Block dequeue(void) {
	return que[fr++];
}

int day = 0;
int board[101][101][101];

//상 하 좌 우 위 아래
int dy[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

//너비우선 탐색으로 전체 일수 구함
void BFS(int m, int n, int h) {
	while (fr < re) {
		Block cur = dequeue();

		for (int dir = 0; dir < 6; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			int nz = cur.z + dz[dir];

			//범위 초과
			if (ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h)
				continue;
			
			//익은 토마토 또는 벽
			if (board[ny][nx][nz] == 1 || board[ny][nx][nz] == -1)
				continue;
			
			//안익은 토마토 발견
			day = cur.dist + 1;
			Block next = { ny, nx, nz, cur.dist + 1 };
			board[ny][nx][nz] = 1; //익은 처리
			enqueue(next);
		}
	}
}

int solution(int M, int N, int H) {
	int answer = 0;
	int flag = 0;

	//일단 BFS로 토마토 익게함
	BFS(M, N, H);

	//안익은 토마토가 있는지 검사
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (board[j][k][i] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}

	if (flag == 0)
		answer = day;
	else
		answer = -1;

	return answer;
}

int main(void) {
	int M, N, H;
	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				scanf("%d", &board[j][k][i]);
				//토마토를 찾았을 경우
				if (board[j][k][i] == 1) {
					Block tomato = { j,k,i,0 };
					enqueue(tomato);
				}
			}
		}
	}

	int ret = solution(M, N, H);
	printf("%d", ret);
	return 0;
}