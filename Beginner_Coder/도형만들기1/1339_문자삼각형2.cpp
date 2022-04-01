#include <iostream>
using namespace std;

char board[100][100];

void print_board(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 0)
				cout << ' ';
			else
				cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	return;
}

void solution(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			board[i][j] = 0;
	}

	char alp = 'A';

	// (1,1)
	// (2,1) (2,2)
	// (3,1) (3,2) (3,3)
	// (4,1) (4,2)
	// (5,1)

	// (n/2,  n/2)
	// (n/2 -1, n/2-1) (n/2, n/2 -1) (n/2 + 1, n/2 - 1)
	// (n/2 -2, n/2 -2) (n/2 -1, n/2 - 2)
	for (int i = n / 2; i >= 0; --i) {
		// 1 -> 3 -> 5로 진행 됌
		for (int j = i; j < n - i; ++j) {
			board[j][i] = alp++;
			if (alp > 'Z')
				alp = 'A';
		}
	}
	return;
}

int main(void) {
	int n;

	cin >> n;
	if (n < 1 || n > 101 || n % 2 == 0)
		cout << "INPUT ERROR\n";

	else {
		solution(n);
		print_board(n);
	}

	return 0;
}
