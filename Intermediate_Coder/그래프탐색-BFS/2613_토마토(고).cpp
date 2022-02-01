#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	int y, x, day;
} TOMATO;

queue<TOMATO> q;
int result = 0;

//상하우좌
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

bool in_Range(int y, int x, int m, int n) {
	return  0 <= y && y < n && 0 <= x && x < m;
}

void BFS(vector<vector<int>>& board, int m, int n) {
	while (!q.empty()) {
		TOMATO cur = q.front();
		q.pop();

		for (int dir = 0; dir<4;++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (in_Range(ny, nx, m, n) && board[ny][nx] == 0) {
				board[ny][nx] = 1;
				result = cur.day + 1;
				q.push({ ny,nx, cur.day + 1 });
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
				q.push({ i,j, 0 });
		}
	}

	BFS(board, m, n);
	answer = result;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0) 
				return-1;
		}
	}
	return answer;
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
