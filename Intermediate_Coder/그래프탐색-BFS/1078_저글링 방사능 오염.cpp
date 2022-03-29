#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#define Max_Size 10012

using namespace std;

typedef struct {
	int y, x;
} Jug;

int board[101][101];
int dist[101][101];

// 상하우좌
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

// 너비탐우선색
pair<int, int> BFS(int n, int m, int jx, int jy) {
	pair<int, int> result = { 0,0 };
	queue<Jug> que;
	int time = -1;

	que.push({ jy,jx });
	dist[jy][jx] = 0;

	while (!que.empty()) {
		int cy = que.front().y;
		int cx = que.front().x;
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			// 범위 초과
			if (ny < 1 || ny > m || nx < 1 || nx > n)
				continue;

			// 재방문
			if (dist[ny][nx] <= dist[cy][cx] + 1)
				continue;
			
			// 벽인 경우
			if (board[ny][nx] == 0)
				continue;

			dist[ny][nx] = dist[cy][cx] + 1;
			que.push({ ny, nx });
		}
	}

	// 어차피 접근한 애들이 죽는 거
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			// 방문했던 것들 중 가장 큰값
			if (dist[i][j] != Max_Size && time < dist[i][j])
				time = dist[i][j];

			// 미방문 저글링
			if (board[i][j] == 1 && dist[i][j] == Max_Size)
				result.second++;
		}
	}

	result.first = time + 3;
	return result;
}

pair<int, int> solution(int n, int m, int jx, int jy) {
	pair<int, int> answer;
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j)
			dist[i][j] = Max_Size;
	}

	// BFS
	answer = BFS(n, m, jx, jy);
	return answer;
}

int main(void) {
	int n, m, jy, jx;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j)
			scanf("%1d", &board[i][j]);
	}

	scanf("%d %d", &jx, &jy);

	pair<int, int> ret = solution(n, m, jx, jy);
	int ans1 = ret.first;
	int ans2 = ret.second;
	cout << ans1 << '\n'; //3초 뒤 죽음
	cout << ans2 << '\n';
	return 0;
}
