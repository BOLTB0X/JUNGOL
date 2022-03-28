#include <iostream>

using namespace std;

int board[5][5];
int cmd[5][5];

void find_check(int y, int x) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[i][j] == cmd[y][x]) {
				board[i][j] = -1; // 지우기
				return;
			}
		}
	}
}

int Count_row(void) {
	int bingo = 0;
	int cnt = 0;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[i][j] == -1) {
				cnt++;
			}
		}
		if (cnt == 5)
			bingo++;
		cnt = 0;
	}

	return bingo;
 }

int Count_col(void) {
	int bingo = 0;
	int cnt = 0;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[j][i] == -1) {
				cnt++;
			}
		}
		if (cnt == 5)
			bingo++;
		cnt = 0;
	}

	return bingo;
 }

int Count_diag(void) {
	// 5 X 5 격자판에 5길이의 대각선은 양 끝쪽 말곤 불가능
	int bingo = 0;
	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (board[i][i] == -1)
			cnt++;
	}

	if (cnt == 5)
		bingo++;

	cnt = 0;
	for (int i = 4; i >= 0; --i) {
		if (board[5 - i - 1][i] == -1)
			cnt++;
	}

	if (cnt == 5)
		bingo++;

	return bingo;
}

int solution(void) {
	int play_cnt = 0;
	int flag = 0;

	while (1) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				find_check(i, j); // 지우기
				play_cnt++; // 카운트

				// 10회 이상 불렀다면
				// 빙고가 되는지 체크
				if (play_cnt >= 10) {
					int bingo = Count_row() + Count_col() + Count_diag();
					if (bingo >= 3) 
						return play_cnt;
					
				}
			}
		}
	}
	return 25;
}

int main(void) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			cin >> board[i][j];
	}
	
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			cin >> cmd[i][j];
	}

	int ret = solution();
	cout << ret;
	return 0;
}