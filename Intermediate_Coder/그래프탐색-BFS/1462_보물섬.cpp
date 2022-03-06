#include <iostream>
#include <vector>
#define MV 2501

using namespace std;

typedef struct {
	int y, x, dist;
} Block;

Block que[MV];
int fr = 0, re = 0;

void enqueue(Block data) {
	que[re++] = data;
	return;
}

Block dequeue(void) {
	return que[fr++];
}

int path = -1;
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

//초기화
void init(vector<vector<int>>& visited, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
			visited[i][j] = MV;
	}
	fr = 0, re = 0;
	return;
}

//너비우선탐색
void BFS(vector<vector<char>> board, vector<vector<int>>& visited, int n, int m, int y, int x) {
	visited[y][x] = 0;
	enqueue({ y,x,0 }); //삽입

	while (fr < re) {
		Block cur = dequeue();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			//범위초과시
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			
			//물을 만날 경우
			if (board[ny][nx] == 'W')
				continue;

			int nd = cur.dist + 1;
			//재방문이고 작다면
			if (visited[ny][nx] <= nd)
				continue;

			if (nd > path) //긴 거리일 경우
				path = nd;
			visited[ny][nx] = nd;
			enqueue({ ny, nx, nd });
		}
	}
	return;
}

int solution(vector<vector<char>> &board, int n, int m) {
	int answer = 0;
	vector<vector<int>> visited(n, vector<int>(m, 0)); //방문리스트 생성

	//완전탐색 방식으로 각 L지점에서 가장 긴거리를 구함
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'L') {
				init(visited, n, m);
				BFS(board, visited, n, m, i, j);
			}
		}
	}

	answer = path;

	return answer;
}

int main(void) {
	int n, m;
	vector<vector<char>> board;
	string tmp;

	cin >> n >> m;
	board.resize(n, vector<char>(m, 0));
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j)
			board[i][j] = tmp[j];
	}

	int ret = solution(board, n, m);
	cout << ret;
	return 0;
}
