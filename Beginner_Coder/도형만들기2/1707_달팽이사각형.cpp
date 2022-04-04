#include <iostream>
#include <cstring>

using namespace std;

int board[101][101];
// 오 상 왼 하
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };

// 범위 체크
int in_Range(int y, int x, int n) {
	return 0 <= y && 0 <= x && y < n && x < n;
}

void print_sq(int n) {
	int number = 1;
	memset(board, 0, n);
	int cy = 0, cx = 0;
	
	// 시뮬
	while (board[cy][cx] == 0 && in_Range(cy, cx, n) == 1) {
		for (int dir = 0; dir < 4; ++dir) {
			if (board[cy][cx] != 0 || in_Range(cy, cx, n) == 0)
				break;


			while (1) {
				board[cy][cx] = number++;
				int ny = cy + dy[dir]; 
				int nx = cx + dx[dir];

				if (board[ny][nx] != 0 || in_Range(ny, nx, n) == 0) {
					cy += dy[(1 + dir) % 4];
					cx += dx[(1 + dir) % 4];
					break;
				}

				cy = ny, cx = nx;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << board[i][j] << ' ';
		cout << "\n";
	}
	
	return;
}

int main(void) {
	int n;
	cin >> n;

	//탈출조건
	if (n > 101) 
		cout << "INPUT ERROR!" << '\n';
	else
		print_sq(n);

	return 0;
}
