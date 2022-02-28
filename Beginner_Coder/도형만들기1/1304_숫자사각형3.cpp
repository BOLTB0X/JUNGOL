#include <iostream>

using namespace std;

int board[100][100];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int number = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			board[j][i] = number++;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	return  0;
}