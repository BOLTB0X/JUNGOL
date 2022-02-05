#include <iostream>
#include <vector>

using namespace std;

void solution(int n, int m) {
	vector<vector<int>> triangle(n + 1, vector<int>(n + 1, 1));

	for (int i = 3; i <= n; ++i) {
		for (int j = 2; j < i; ++j) {
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
		}
	}

	if (m == 1) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j)
				cout << triangle[i][j] << ' ';
			cout << "\n";
		}
	}

	else if (m == 2) {
		for (int i = n; i >= 1; --i) {
			for (int j = n; j > i; --j)
				cout << " ";
			for (int j = 1; j <= i; ++j)
				cout << triangle[i][j] << " ";
			cout << "\n";
		}
	}
	
	else if (m == 3) {
		for (int i = n; i >= 1; --i) {
			for (int j = n; j >= i; --j)
				cout << triangle[j][i] << ' ';
			cout << "\n";
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

	return 0;
}