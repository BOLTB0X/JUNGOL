#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int area = 0;
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };

void DFS(vector<vector<int>>& board, vector<vector<int>>& visited, int n, int m, int x, int y) {
	area++;
	visited[x][y] = 1;

	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (0 > nx || 0 > ny || nx >= n || ny >= m)
			continue;
		if (board[nx][ny] != 0 || visited[nx][ny] == 1)
			continue;

		DFS(board, visited, n, m, nx, ny);
	}
	return;
}

void solution(vector<vector<int>>& pos, int m, int n) {
	vector<int> result;

	vector<vector<int>> board;
	vector<vector<int>> visited;
	board.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<int>(m, 0));

	for (auto &p: pos) {
		int x1 = p[0], y1 = p[1], x2 = p[2], y2 =p[3];
		for (int x = x1; x < x2; ++x) {
			for (int y = y1; y < y2; ++y) 
				board[x][y] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0 && visited[i][j] == 0) {
				area = 0;
				DFS(board, visited, n, m, i, j);
				if (area != 0)
					result.push_back(area);
			}
		}
	}
	cout << result.size() << '\n';
	sort(result.begin(), result.end());

	for (auto& r : result) 
		cout << r << ' ';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n, k;
	cin >> m >> n >> k;

	vector<vector<int>> pos;
	pos.resize(k, vector<int>(4,0));

	for (int i = 0; i < k; ++i) 
		cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3];

	solution(pos, m, n);
	return  0;
}