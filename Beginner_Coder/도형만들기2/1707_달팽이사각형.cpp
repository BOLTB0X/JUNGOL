#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };

bool in_Range(vector<vector<int>>& sq, int n, int y, int x) {
	return 1 <= y && y <= n && 1 <= x && x <= n;
}

void print_sq(vector<vector<int>>& sq, int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << sq[i][j] << ' ';
		cout << '\n';
	}
	return;
}

void solution(int n) {
	vector<vector<int>> sq(n + 1, vector<int>(n + 1, 0));
	int number = 1;
	int y = 1, x = 1;

	while (in_Range(sq, n, y, x) && sq[y][x] == 0) {
		for (int dir = 0; dir < 4; ++dir) {
			if (!in_Range(sq, n, y, x) || sq[y][x] != 0)
				break;
			while (1) {
				sq[y][x] = number++;
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (!in_Range(sq, n, ny, nx) || sq[ny][nx] != 0) {
					y += dy[(1 + dir) % 4];
					x += dx[(1 + dir) % 4];
					break;
				}

				y = ny;
				x = nx;
			}
		}
	}

	print_sq(sq, n);
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	solution(n);

	return 0;
}