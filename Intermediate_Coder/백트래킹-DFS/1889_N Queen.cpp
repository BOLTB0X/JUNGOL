#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n;
int result = 0;
int board[15];

int abs(int a) {
	return a < 0 ? -a : a;
}

bool is_Process(int y) {
	for (int i = 0; i < y; ++i) {
		if (board[y] == board[i] || y - i == abs(board[y] - board[i]))
			return 0;
	}

	return 1;
}

void backTracking(int y) {
	if (n == y) {
		result++;
		return;
	}
	for (int x = 0; x < n; ++x) {
		board[y]= x;
		if (is_Process(y)) 
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