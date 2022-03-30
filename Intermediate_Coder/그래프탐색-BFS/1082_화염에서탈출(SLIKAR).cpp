#include <iostream>
#define Max_Size 2511

using namespace std;

typedef struct {
	int y, x, dist;
} Node;

Node que[Max_Size];
int fr = 0, re = 0;

char board[51][51];
int visited[51][51];

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

void push(int y, int x, int dist) {
	// 재방문 방지
	if (visited[y][x] <= dist)
		return;

	visited[y][x] = dist;
	que[re++] = { y,x, dist };
	return;
}

// 너비우선탐색
void BFS(int n, int m) {
	while (fr < re) {
		int cy = que[fr].y;
		int cx = que[fr].x;
		int cd = que[fr].dist;
		fr++; // pop

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			int nd = cd + 1;

			// 범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			push(ny, nx, nd);
		}
	}
	return;
}

int solution(int n, int m) {
	int answer = -1;
	int sy = 0, sx = 0, ey = 0, ex = 0;

	// 좌표 정리
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = Max_Size;
			// 불을 발견하면
			if (board[i][j] == '*')
				push(i, j, 0);

			// 재우를 발견하면
			else if (board[i][j] == 'S') {
				sy = i;
				sx = j;
			}

			// 집을 발견하면
			else if (board[i][j] == 'D') {
				ey = i;
				ex = j;
			}

			// 바위를 발견하면
			else if (board[i][j] == 'X')
				visited[i][j] = 0; // 방문 처리
		}
	}

	// 먼저 불부터 visited에 방문 시간을 남김
	visited[ey][ex] = 0; //요새에 옮기지 못하므로
	BFS(n, m);

	// 불의 정보를 남겼으므로
	// 재우 진행
	fr = 0, re = 0; // 초기화
	visited[ey][ex] = Max_Size;
	push(sy, sx, 0);
	BFS(n, m);

	// 도달한다면
	if (visited[ey][ex] < Max_Size)
		answer = visited[ey][ex];
	return answer;
}

int main(void) {
	int n, m;
	int sy = 0, sx = 0, ey = 0, ex = 0;
	string str;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < m; ++j)
			board[i][j] = str[j];
	}

	int ret = solution(n, m);
	if (ret == -1)
		cout << "impossible";
	else
		cout << ret;

	return 0;
}
