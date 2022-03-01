#include <iostream>
using namespace std;

char board[100][100];

void print_board(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	return;
}

void solution(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			board[i][j] = ' ';
	}

	char alp = 'A';

	//배열을 채우는 순서
	//(1, 5) (2, 4) (3, 3) (4, 2) (5, 1) (2, 5) (3, 4) 
	//(4, 3) (5, 2) (3, 5) (4, 4) (5, 3) (4, 5) (5, 4) (5, 5) 
	for (int i = 0; i < n; i++) {
		for (int j = i, k = n - 1; j < n; j++, k--) {
			board[j][k] = alp++;
			if (alp > 'Z')
				alp = 'A';
		}
	}
	return;
}

int main(void) {
	int n;

	cin >> n;

	solution(n);

	print_board(n);

	return 0;
}