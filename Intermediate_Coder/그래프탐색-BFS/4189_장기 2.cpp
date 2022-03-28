#include <iostream>
#include <vector>
#define MS 1001

using namespace std;

typedef struct {
	int y, x;
} Pair;

Pair que[MS * MS];
int fr = 0, re = 0;

void enqueue(Pair data) {
	que[re++] = data;
	return;
}

Pair dequeue(void) {
	return que[fr++];
}

vector<vector<int>> visited;

const int dy[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int dx[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int solution(int n, int m, int sy, int sx, int ey, int ex) {
	int answer = 0;

	visited.resize(n + 1, vector<int>(m + 1, 0x7fffffff));

	enqueue({ sy, sx});
	visited[sy][sx] = 0;

	//너비우선탐색
	while (fr < re) {
		Pair cur = dequeue();

		//잡았다면
		if (cur.y == ey && cur.x == ex)
			break;

		for (int dir = 0; dir < 8; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//범위초과
			if (ny < 1 || nx < 1 || ny > n || nx > m)
				continue;

			int nd = visited[cur.y][cur.x] + 1;
			if (visited[ny][nx] <= nd)
				continue;

			visited[ny][nx] = nd;
			enqueue({ ny, nx });
		}
	}

	answer = visited[ey][ex];
	return answer;
}

int main(void) {
	int n, m;
	int sy, sx, ey, ex;

	cin >> n >> m;
	cin >> sy >> sx >> ey >> ex;

	int ret = solution(n, m, sy, sx, ey, ex);
	cout << ret;
	return 0;
}