#include <iostream>
#include <vector>
#define Max_Size 1001 // 최대 길이

using namespace std;

typedef struct {
	int y, x, day;
} Tomato;

Tomato que[Max_Size * Max_Size];
int fr = 0, re = 0;

void enqueue(Tomato data) {
	que[re++] = data;
	return;
}

int board[Max_Size][Max_Size];
vector<vector<int>> visited;

// 상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int BFS(int n, int m, vector<vector<int>>& visited) {
	int result = 0;

	// BFS
	while (fr < re) {
		int cy = que[fr].y;
		int cx = que[fr].x;
		int cday = que[fr].day;
		fr++; // pop

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 1 || nx < 1 || ny > m || nx > n)
				continue;

			// 안익은 토마토가 아니면
			if (board[ny][nx] != 0)
				continue;

			if (visited[ny][nx] == 1)
				continue;

			visited[ny][nx] = 1;
			result = cday + 1;
			board[ny][nx] = 1;
			enqueue({ ny, nx, cday + 1 });
		}
	}

	return result;
}

int solution(int n, int m) {
	int answer = 0;
	visited.resize(m + 1, vector<int>(n + 1, 0)); // 방문리스트

	// 익은 토마토 찾기
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			// 토마토 발견
			if (board[i][j] == 1) {
				enqueue({ i,j,0 });
				visited[i][j] = 1;
			}
			
		}
	}

	answer = BFS(n, m, visited);

	// 안 익은 토마토 찾기
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (board[i][j] == 0)
				return -1;

		}
	}

	return answer;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}

	int ret = solution(n, m);
	cout << ret;
	
	return 0;
}
