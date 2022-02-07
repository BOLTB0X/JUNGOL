#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
	int y, x;
	int cnt;
} JUG;

int board[101][101];
int juggle[101][101];
bool visited[101][101];

//상하우좌
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

//깊이너비탐색
pair<int, int> BFS(int n, int m, int jx, int jy) {
	pair<int, int> result = { 0,0 };
	queue<JUG> que;
	int time = -1;

	que.push({ jy,jx,0 });
	visited[jy][jx] = true;

	while (!que.empty()) {
		int cy = que.front().y;
		int cx = que.front().x;
		int cnt = que.front().cnt;
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			//범위 초과
			if (ny < 1 || ny > m || nx < 1 || nx > n)
				continue;

			//재방문
			if (visited[ny][nx] == 1)
				continue;

			if (board[ny][nx] == 1) {
				juggle[ny][nx] = cnt + 1;
				visited[ny][nx] = true;
				que.push({ ny, nx, cnt + 1 });
			}
		}
	}

	//어차피 접근한 애들이 죽는 거
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (time < juggle[i][j])
				time = juggle[i][j];
			if (board[i][j] == 1 && !visited[i][j])
				result.second++;
		}
	}
	
	result.first = time;
	return result;
}

pair<int,int> solution(int n, int m, int jx, int jy) {
	pair<int,int> answer;
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			juggle[i][j] = 0;
			visited[i][j] = false;
		}
	}
	answer = BFS(n, m, jx, jy);
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, jy, jx;

	scanf("%d %d",&n,&m);

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j)
			scanf("%1d",&board[i][j]);
	}

	scanf("%d %d", &jx, &jy);

	pair<int,int> ret = solution(n, m, jx, jy);
	int ans1 = ret.first + 3;
	int ans2 = ret.second;
	cout << ans1 << '\n'; //3초 뒤 죽음
	cout << ans2 << '\n';
	return 0;
}