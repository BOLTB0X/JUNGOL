#include <iostream>

using namespace std;

typedef struct {
	int y, x, dist;
} Node;

Node que[2501];
int fr = 0, re = 0;

void enqueue(Node data) {
	que[re++] = data;
	return;
}

void dequeue(void) {
	fr++;
	return;
}

int n, m, result = -1;
char board[50][50];
int visited[50][50];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

int MAX(int a, int b) {
	return a > b ? a : b; //반환
}

void init(void) {
	fr = 0, re = 0; //큐 초기화
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			visited[i][j] = 2501;
	}
	return;
}

void BFS(int y, int x) {
	enqueue({ y,x,0 });
	visited[y][x] = 0;

	//비어질때까지
	while (fr < re) {
		int cy = que[fr].y;
		int cx = que[fr].x;
		int cd = que[fr].dist;
		dequeue();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			//범위초과
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			//이동 불가
			if (board[ny][nx] == 'W')
				continue;

			int nd = cd + 1;
			if (visited[ny][nx] <= nd) //작다면 재방문
				continue;

			result = MAX(result, nd); //가장 긴 시간 걸리는 곳이니
			visited[ny][nx] = nd;
			enqueue({ ny,nx,nd });
		}
	}
	return;
}

void solution(void) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'L') {
				init(); //초기화
				BFS(i, j); //여기에서 각 보물 묻힌 곳이라 가정
			}
		}
	}
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string tmp;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j)
			board[i][j] = tmp[j];
	}

	solution();

	cout << result;
	return 0;
}
