#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = { 1,1,-1,-1 };
const int dx[4] = { -1,1,1,-1 };

void print_rh(vector<vector<char>>& rh, int n) {
	int left = n, right = n;

	for (int i = 1; i <= 2*n - 1; ++i) {
		for (int j = 1; j < left; ++j)
			cout << "  ";
		for (int j= left; j <= right; ++j)
			cout << rh[i][j] << ' ';

		if (i < n)
			left--, right++;
		else
			left++, right--;
		cout << '\n';
	}
	return;
}

void solution(int n) {
	vector<vector<char>> rh(2*n + 1, vector<char>(2*n + 1));
	int size = n;
	char alp = 'A';

	for (int i = 1; i < n; ++i) {
		int cy = i, cx = n;
		for (int dir = 0; dir < 4; ++dir) {
			for (int j = 1; j < size; ++j) {
				rh[cy][cx] = alp++;
				if (alp > 'Z')
					alp = 'A';

				cy += dy[dir];
				cx += dx[dir];
			}
		}
		size--;
	}
	rh[n][n] = alp;


	print_rh(rh, n);
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