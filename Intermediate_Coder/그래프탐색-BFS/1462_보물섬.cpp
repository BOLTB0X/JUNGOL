#include <iostream>
#include <queue>

using namespace std;

int n, m, result = -1;
char board[50][50];
int visited[50][50];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

int max(int a, int b) {
	return a > b ? a : b;
}

void init(void) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			visited[i][j] = 2501;
	}
	return;
}

void BFS(int y, int x) {
	queue<pair<pair<int, int>, int>> que;
	visited[y][x] = 0;
	que.push({ {y,x},0 });

	while (!que.empty()) {
		int cy = que.front().first.first;
		int cx = que.front().first.second;
		int c_d = que.front().second;
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (board[ny][nx] == 'W')
				continue;

			int next_dist = c_d + 1;
			if (visited[ny][nx] <= next_dist)
				continue;

			visited[ny][nx] = next_dist;
			que.push({ {ny,nx},next_dist });
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visited[i][j] != 2501)
				result = max(result, visited[i][j]);
		}
	}

	return;
}

void solution(void) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'L') {
				init();
				BFS(i, j);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string tmp;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j)
			board[i][j] = tmp[j];
	}

	solution();

	cout << result;
	return 0;
}