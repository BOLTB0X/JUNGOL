#include <iostream>

using namespace std;

int board[101][101];

void solution(int n, int m) {
	if (m == 1) {
		int number = 0;
		for (int i = 0; i < n; ++i) {
			number++;
			for (int j = 0; j < n; ++j)
				board[i][j] = number;
		}
	}

	else if (m == 2) {
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) {
				int number = 1;
				for (int j = 0; j < n; ++j)
					board[i][j] = number++;
			}
			else {
				int number = n;
				for (int j = 0; j < n; ++j)
					board[i][j] = number--;
			}
		}
	}

	else if (m == 3) {
		for (int i = 0; i < n; ++i) {
			int number = i + 1;
			for (int j = 0; j < n; ++j) {
				board[i][j] = number;
				number = number + (i + 1);
			}
		}
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	solution(n, m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			cout << board[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}