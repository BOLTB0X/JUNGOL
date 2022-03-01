#include <iostream>
#include <vector>
#define ML 1000001

using namespace std;

typedef struct {
	int y, x, day;
} TOMATO;

TOMATO que[ML];
int fr = 0, re = 0;

void enqueue(TOMATO data) {
	que[re++] = data;
	return;
}

TOMATO dequeue(void) {
	return que[fr++];
}

int result = 0;

//상하좌우
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

//범위 반환
int in_Range(int y, int x, int m, int n) {
	return  0 <= y && y < n && 0 <= x && x < m;
}

//너비우선 탐색
void BFS(vector<vector<int>>& board, int m, int n) {
	while (fr < re) {
		TOMATO cur = dequeue();

		for (int dir = 0; dir<4;++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (in_Range(ny, nx, m, n) && board[ny][nx] == 0) {
				board[ny][nx] = 1;
				result = cur.day + 1;
				enqueue({ ny,nx, cur.day + 1 });
			}
		}
	}
	return;
}

int solution(vector<vector<int>>& board, int m, int n) {
	int answer = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			//토마토 좌표 
			if (board[i][j] == 1)
				enqueue({ i,j, 0 });
		}
	}

	BFS(board, m, n);
	answer = result;

	//안익은 토마토가 있으면
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0) 
				return -1;
		}
	}

	//반환
	return answer;
}

int main(void) {
	//초기화
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
