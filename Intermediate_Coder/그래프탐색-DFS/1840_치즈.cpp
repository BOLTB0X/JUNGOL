#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

// 녹을 수 있는 치즈가 있는 가?
int is_Melting(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1)
				return 1;
		}
	}
	return 0;
}

// DFS으로 가장자리 탐색 - > 0인 지점에서 상하좌우로 탐색해서 1인걸 찾으면 바꿔주면 됌
// 치즈 - > 공기는 -1처리
// 가장자리 체크
void DFS(int n, int m, int y, int x) {
	if (board[y][x] == 0) {
		board[y][x] = -1; // 방문리스트 대체

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// 치즈 발견, 체크만하고 이동 X
			if (board[ny][nx] == 1)
				board[ny][nx] = 2;

			//공기발견
			if (board[ny][nx] == 0)
				DFS(n, m, ny, nx);
		}
	}

	return;
}

pair <int, int> solution(int n, int m) {
	pair<int, int> answer = { 0,0 };
	int cnt;

	// 녹을 치즈가 없을 때까지 
	while (is_Melting(n, m) == 1) {
		answer.first++;
		cnt = 0;
		DFS(n, m, 0, 0);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				// 원상 복구
				if (board[i][j] == -1)
					board[i][j] = 0;

				// 녹을 치즈 발견
				if (board[i][j] == 2) {
					cnt++;
					board[i][j] = 0; // 공기 처리
				}
			}
		}
	}
	answer.second = cnt; // 바로 전 치즈

	return answer;
}

int main(void) {
	int n, m;
	
	cin >> n >> m;
	board.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
			cin >> board[i][j];
	}

	pair<int, int> ret = solution(n, m);
	
	cout << ret.first << "\n" << ret.second;

	return 0;
}
