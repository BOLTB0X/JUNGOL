#include <iostream>

using namespace std;

void solution(int n, int m) {
	if (m == 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j)
				cout << "*";
			cout << '\n';
		}
	}
	else if (m == 2) {
		for (int i = n; i >= 1; --i) {
			for (int j = 0; j < i; ++j)
				cout << "*";
			cout << '\n';
		}
	}
	else if (m == 3) {
		for (int i = n; i >= 1; --i) {
			for (int j = 0; j < i - 1; ++j)
				cout << ' ';
			for (int j = 0; j < 2 * (n - i) + 1; ++j)
				cout << "*";
			cout << '\n';
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

	if (n >= 1 && n <= 100 && m >= 1 && m <= 3)
		solution(n, m);
	else
		cout << "INPUT ERROR!";
	return 0;
}