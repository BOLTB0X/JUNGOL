#include <iostream>
#include <vector>

using namespace std;

int board[101][101];

// 대각선, 좌, 하
const int dy[3] = { 1,0,-1 };
const int dx[3] = { 1,-1, 0 };

// 범위 체크
int in_Range(int y, int x, int n) {
	return 0 <= y && 0 <= x && y < n && x < n;
}

void init(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			board[i][j] = -1;
	}
}

vector<vector<int>> solution(int n) {
	vector<vector<int>> answer(n);
	init(n);

	int number = 0;
	int cy = 0, cx = 0;
	while (board[cy][cx] == -1 && in_Range(cy, cx, n) == 1) {
		for (int dir = 0; dir < 3; ++dir) {
			if (board[cy][cx] != -1 || in_Range(cy, cx, n) == 0)
				break;

			while (1) {
				board[cy][cx] = number++;
				if (number > 9)
					number = 0;

				int ny = cy + dy[dir];
				int nx = cx + dx[dir];

				if (board[ny][nx] != -1 || in_Range(ny, nx, n) == 0) {
					cy += dy[(1 + dir) % 3];
					cx += dx[(1 + dir) % 3];
					break;
				}
				cy = ny, cx = nx;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) 
			answer[i].push_back(board[i][j]);
	}
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	vector<vector<int>> ret = solution(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) 
			cout << ret[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
