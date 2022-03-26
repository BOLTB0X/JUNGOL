#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int area;
vector<vector<int>> board;
vector<vector<int>> visited;

//상하좌우
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,-1,1 };

// 깊이우선탐색
void DFS(int n, int m, int x, int y) {
	visited[x][y] = 1;
	area++;

	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dy[dir];
		int ny = y + dx[dir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (visited[nx][ny] == 1)
			continue;
		if (board[nx][ny] == 1)
			continue;

		DFS(n, m, nx, ny);
	}
	return;
}

vector<int> solution(vector<vector<int>>& pos, int m, int n) {
	vector<int> result;
	board.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<int>(m, 0));

	// 먼저 색칠해줌
	for (vector<int>& p : pos) {
		int x1 = p[0];
		int y1 = p[1];
		int x2 = p[2];
		int y2 = p[3];

		for (int i = x1; i < x2; ++i) {
			for (int j = y1; j < y2; ++j)
				board[i][j] = 1; // 색칠
		}
	}

	// 색칠된 것을 바타으로 0인 지점에서 DFS탐색
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0 && visited[i][j] == 0) {
				area = 0;
				DFS(n, m, i, j);
				result.push_back(area);
			}
		}
	}

	sort(result.begin(), result.end());
	return result;
}

int main(void) {
	int m, n, k;
	cin >> m >> n >> k;

	vector<vector<int>> pos;
	pos.resize(k, vector<int>(4,0));
	
	for (int i = 0; i < k; ++i) 
		cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3];

	vector<int>  ret = solution(pos, m, n);
	cout << ret.size() << '\n';
	for (int& r : ret)
		cout << r << ' ';
	return  0;
}
