#include <iostream>

using namespace std;

char board[101][101];

void print_board(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) 
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	return;
}

void solution(int n) {
	// 초기화
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			board[i][j] = ' ';
	}

	char alp = 'A';
	// 삼각형의 시작방향을 생각하면 됌
	// (1, 5)
	// (2, 4) (2,5)
	// (3, 3) (3, 4) (3, 5)
	for (int i = 1; i <= n; ++i) {
		for (int j = i, k = n; j <= n; ++j, --k) {
			board[j][k] = alp++;
			if (alp > 'Z')
				alp = 'A'; // 초기화
		}
	}
	
	return;
}

int main(void) {
	int n;

	cin >> n;

	solution(n); 
	print_board(n); // 출력

	return 0;
}
