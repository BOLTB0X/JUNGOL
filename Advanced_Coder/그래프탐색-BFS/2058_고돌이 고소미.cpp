#include <iostream>
#include <vector>
#define INF 26 * 26 * 26 * 26 //큐의 최대길이

using namespace std;

vector<vector<int>> board;
int visited[26][26][26][26];

const int dy[9] = { -1, 1, 0, 0, -1, -1, 1, 1, 0 };
const int dx[9] = { 0, 0, -1, 1, -1, 1, -1, 1, 0 };

typedef struct {
	int gy, gx, sy, sx, dist;
} Go;

Go que[INF];
int fr = 0, re = 0;

int Abs(int a) {
	return a < 0 ? -a : a;
}

void enqueue(Go data) {
	que[re++] = data;
	return;
}

Go dequeue(void) {
	return que[fr++];
}

//범위 초과
int in_Range(int y, int x, int n) {
	return 1 <= y && y <= n && 1 <= x && x <= n;
}

//너비우선탐색
int BFS(int n, int end_gy, int end_gx, int end_sy, int end_sx) {
	while (fr < re) {
		Go cur = dequeue();

		//각자 목적지에 도달했다면
		if (cur.gy == end_gy && cur.gx == end_gx && cur.sy == end_sy && cur.sx == end_sx) 
			return cur.dist;
		
		// 두 고슴도치가 가질 수 있는 모든 경우
		for (int i = 0; i < 9; ++i) {
			int ngy = cur.gy + dy[i];
			int ngx = cur.gx + dx[i];

			//범위초과
			if (in_Range(ngy, ngx, n) == 0)
				continue;
			
			//물웅덩이인 경우
			if (board[ngy][ngx] == 1)
				continue;

			for (int j = 0; j < 9; ++j) {
				int nsy = cur.sy + dy[j];
				int nsx = cur.sx + dx[j];

				//범위 초과인 경우
				if (in_Range(nsy, nsx, n) == 0)
					continue;

				//물웅덩이인 경우
				if (board[nsy][nsx] == 1)
					continue;

				//재방문인경우
				if (visited[ngy][ngx][nsy][nsx] == 1)
					continue;

				//각 위치의 거리가 1이하인 경우
				if (Abs(ngy - nsy) <= 1 && Abs(ngx - nsx) <= 1)
					continue;

				visited[ngy][ngx][nsy][nsx] = 1;
				enqueue({ ngy, ngx, nsy, nsx, cur.dist + 1 });
			}
		}
	}
	return -1;
}

int solution(int n, int gy1, int gx1, int gy2, int gx2, int sy1, int sx1, int sy2, int sx2) {
	int answer = 0;

	enqueue({ gy1, gx1, sy1, sx1, 0 });
	visited[gy1][gx1][sy1][sx1] = 1; //방문처리

	answer = BFS(n, gy2, gx2, sy2, sx2);

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int gy1, gx1, gy2, gx2 ,sy1, sx1, sy2, sx2; // 고돌 , 고소

	cin >> n;
	cin >> gy1 >> gx1 >> gy2 >> gx2;
	cin	>> sy1 >> sx1 >> sy2 >> sx2;
	board.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}

	int ret = solution(n, gy1, gx1, gy2, gx2, sy1, sx1, sy2, sx2);
	cout << ret;

	return 0;
}