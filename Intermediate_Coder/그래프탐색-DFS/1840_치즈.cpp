#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
vector<vector<int>> board;
//상하우좌
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

//녹을 치즈 있는지 확인
int is_Melting(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1)
				return 1;
		}
	}
	return 0;
}

//DFS으로 가장자리 탐색 - > 0인 지점에서 상하좌우로 탐색해서 1인걸 찾으면 바꿔주면 됌
//치즈 - > 공기는 -1처리
void DFS(int n, int m, int y, int x) {
	if (board[y][x] == 0) {
		board[y][x] = -1; //방문리스트가 없으니 
		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			//범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			//가장자리 치즈 발견
			if (board[ny][nx] == 1)
				board[ny][nx] = 2;

			//다시 공기 발견
			if (board[ny][nx] == 0)
				DFS(n, m, ny, nx);
		}
	}
	return;
}

pair<int, int> solution(int n, int m) {
	pair<int, int> answer(0, 0);
	
	//시뮬시작
	while (is_Melting(n, m) == 1) {
		answer.first++; //전체 라운트 카운트
		cnt = 0;

		DFS(n, m, 0, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				//원상복구
				if (board[i][j] == -1)
					board[i][j] = 0;
				//녹을 치즈
				if (board[i][j] == 2) {
					cnt++;
					//녹아질 치즈 제거
					board[i][j] = 0;
				}
			}
		}
	}
	
	//바로 전 치즈 갯수 
	answer.second = cnt;

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
