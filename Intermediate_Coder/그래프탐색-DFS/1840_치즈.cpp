#include <iostream>
#include <vector>

using namespace std;

int cnt;

//상하우좌
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

//범위 내
int in_Range(int y, int x, int n, int m) {
	return 0 <= y && 0 <= x && y < n && x < m;
}

//녹을 수 있는 치즈가 존재하는가
int is_Melting(vector<vector<int>>& board, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1)
				return 1;
		}
	}
	return 0;
}

//DFS로 가장자리 치즈들 공기로 제거
//치즈 -> 공기 는 -1처리
//다음 턴에 공기될 치즈는 2로 처리
void DFS(vector<vector<int>>& board, int n, int m, int y, int x) {
	if (in_Range(y, x, n, m)) {
		if (board[y][x] == 0) {
			board[y][x] = -1;

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (in_Range(ny, nx, n, m) && board[ny][nx] == 1)
					board[ny][nx] = 2;
				if (in_Range(ny, nx, n, m) && board[ny][nx] == 0)
					DFS(board, n, m, ny, nx);
			}
		}
		return;
	}
	return;
}

pair<int ,int> solution(vector<vector<int>>& board, int n, int m) {
	pair<int, int> answer;
	
	while (is_Melting(board, n, m)) {
		answer.first++;
		//녹는 동안 남은 치즈 갯수를 체크하기 위해 초기화
		cnt = 0;
		DFS(board, n, m, 0, 0);

		//녹아질 치즈 제거
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == -1)
					board[i][j] = 0;
				else if (board[i][j] == 2) {
					cnt++;
					board[i][j] = 0;
				}
					
			}
		}
	}

	answer.second = cnt;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<vector<int>> board;

	cin >> n >> m;
	board.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	pair<int, int> ret = solution(board, n, m);

	cout << ret.first << '\n';
	cout << ret.second;

	return 0;
}