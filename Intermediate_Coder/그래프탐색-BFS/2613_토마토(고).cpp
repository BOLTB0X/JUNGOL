#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

//»óÇÏÁÂ¿ì
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

bool in_Range(int y, int x, int m, int n) {
	return  0 <= y && y < n && 0 <= x && x < m;
}

void BFS(vector<vector<int>>& board, int m, int n) {
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir<4;++dir) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (in_Range(ny, nx, m, n) && board[ny][nx] == 0) {
				board[ny][nx] = board[cur.first][cur.second] + 1;
				q.push({ ny,nx });
			}
		}
	}
	return;
}

int solution(vector<vector<int>>& board, int m, int n) {
	int answer = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1)
				q.push({ i,j });
		}
	}

	BFS(board, m, n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0)
				return -1;
			if (answer < board[i][j])
				answer = board[i][j];
		}
	}
	
	return answer - 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	vector<vector<int>> board;
	cin >> m >> n;
	board.resize(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}
	
	int ret = solution(board, m, n);

	cout << ret << '\n';
	return 0;
}