#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n;
int result = 0;
int board[15];

//절댓값 반환
int Abs(int a) {
	return a < 0 ? -a : a;
}

int is_Process(int y) {
	//해당 행과 열의 정보를 확인해야함
	for (int i = 0; i < y; ++i) {
		//같은 위치에 있는지 확인
		if (board[y] == board[i] || y - i == Abs(board[y] - board[i]))
			return 0;
	}
	return 1;
}

void backTracking(int y) {
	//행이 n까지 갔다면
	if (y == n) {
		result++;
		return;
	}

	for (int x = 0; x < n; ++x) {
		board[y] = x; //열 정보 삽입
		if (is_Process(y) == 1)
			backTracking(y + 1);
	}
	return;
}

int main(void) {
	scanf("%d", &n);

	backTracking(0);
	printf("%d", result);
	
	return 0;
}
