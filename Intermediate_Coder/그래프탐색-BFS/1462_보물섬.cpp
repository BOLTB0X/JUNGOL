#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define Max_Size 2511

using namespace std;

int path;
char board[51][51];
vector<vector<int>> dist;

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

void BFS(int n, int m, int sy, int sx) {
	queue<pair<int, int>> que;
	que.push({ sy, sx });
	dist[sy][sx] = 0;

	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			// 범위 초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// 물
			if (board[ny][nx] == 'W')
				continue;

			// 재방문
			if (dist[ny][nx] <= dist[cy][cx] + 1)
				continue;

			dist[ny][nx] = dist[cy][cx] + 1;
			// 거리 교체
			if (path < dist[ny][nx])
				path = dist[ny][nx];
			que.push({ ny, nx });
		}
	}

	return;
}

int solution(int n, int m) {
	int answer = 0;
	path = -1; // 최대를 위한

	// 완전탐색식으로
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// 육지
			if (board[i][j] == 'L') {
				// 초기화
				dist = vector<vector<int>>(n, vector<int>(m, Max_Size));
				BFS(n, m, i, j);
			}
		}
	}

	answer = path;
	return answer;
}

int main(void) {
	int n, m;
	string tmp;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j)
			board[i][j] = tmp[j];
	}

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
