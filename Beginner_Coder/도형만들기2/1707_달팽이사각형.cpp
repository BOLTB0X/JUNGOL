#include <iostream>
#include <cstring>
using namespace std;

int board[101][101];
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };

int in_Range(int n, int y, int x) {
	return 1 <= y && 1 <= x && y <= n && x <= n;
}

void print_sq(int n) {
	int number = 1;
	int y = 1, x = 1;

	//초기화
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			board[i][j] = 0;
	}

	while (in_Range(n, y, x) == 1 && board[y][x] == 0) {
		for (int dir = 0; dir < 4; ++dir) {
			if (in_Range(n, y, x) == 0 || board[y][x] != 0)
				break;

			while (1) {
				board[y][x] = number++;
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (in_Range(n, ny, nx) == 0 || board[ny][nx] != 0) {
					y += dy[(1 + dir) % 4];
					x += dx[(1 + dir) % 4];
					break;
				}

				y = ny; 
				x = nx;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
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
