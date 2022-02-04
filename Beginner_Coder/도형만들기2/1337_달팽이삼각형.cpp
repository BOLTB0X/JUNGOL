#include <iostream>
#include <cstring>

using namespace std;

int board[100][100];
//¥ﬁ∆ÿ¿Ã πÊ«‚
const int dy[3] = { 1,0,-1 };
const int dx[3] = { 1,-1,0 };

bool in_Range(int sy, int sx, int n) {
	return 0 <= sy && sy < n && 0 <= sx && sx < n;
}

void init_pane(int n) {
	for (int i = 0; i < n; ++i)
		memset(board[i], -1, sizeof(int) * n);
	return;
}

void print_board(int n) {
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x <= y; ++x)
            cout << board[y][x] << ' ';
        cout << "\n";
    }
    return;
}

void solution(int n) {
    init_pane(n);

    int cy = 0, cx = 0;
    int number = 0;

    while (in_Range(cy, cx, n) && board[cy][cx] == -1) {
        for (int dir = 0; dir < 3; ++dir) {
            if (!in_Range(cy, cx, n) || board[cy][cx] != -1)
                break;

            while (true) {
                board[cy][cx] = number % 10;
                number++;
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];

                if (!in_Range(ny, nx, n) || board[ny][nx] != -1) {
                    cy += dy[(dir + 1) % 3];
                    cx += dx[(dir + 1) % 3];
                    break;
                }

                cy = ny;
                cx = nx;
            }
        }
    }

    print_board(n);
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