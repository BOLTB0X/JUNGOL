#include <iostream>

using namespace std;

int board[19][19];
const int dy[4] = { 1,0,-1,1 };
const int dx[4] = { 0,1,1,1 };

int check(int y, int x) {
	int type = board[y][x];
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		int cnt = 1;

		while (0 <= ny && 0 <= nx && ny < 19 && nx < 19 && board[ny][nx] == type) {
			cnt++;

			// ������ �ϼ��Ǹ�
			if (cnt == 5) {
				// �������� üũ
				if (0 <= ny + dy[dir] && 0 <= nx + dx[dir] && ny + dy[dir] < 19 && nx + dx[dir] < 19 && board[ny + dy[dir]][nx + dx[dir]] == type)
					break;
				
				// �������� üũ
				if (0 <= ny - dy[dir] && 0 <= nx - dx[dir] && ny - dy[dir] < 19 && nx - dx[dir] < 19 && board[y - dy[dir]][x - dx[dir]] == type)
					break;
				
				return 1;
			}
			ny += dy[dir];
			nx += dx[dir];
		}
	}
	return 0;
}

void solution(void) {
	int player = -1, ay, ax;

	int flag = 0;
	// �� ���� ������
	// ���� ��, ��, �Ʒ�, �밢��(�� -> ��), (��)
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			// üũ
			if (board[i][j] != 0 && check(i, j) == 1) {
				player = board[i][j];
				ay = i, ax = j;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	if (player == -1)
		cout << '0';
	else {
		cout << player << '\n';
		cout << ay + 1 << ' ' << ax + 1;
	}
	return;
}

int main(void) {
	// ������ �Է�
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j)
			cin >> board[i][j];
	}

	solution();
	return  0;
}