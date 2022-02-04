#include <iostream>

using namespace std;

void solution(int n, int m) {
	if (m == 1) {
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j <= i; ++j)
				cout << "*";
			cout << '\n';
		}
		for (int i = 0; i <= n / 2; ++i) {
			for (int j = n/2 -i; j >= 0; --j)
				cout << "*";
			cout << '\n';
		}
	}
	else if (m == 2) {
		for (int i = 0; i < n / 2; ++i) {
			for (int j = n / 2 - i; j > 0; --j)
				cout << " ";
			for (int j = 0; j <= i; ++j)
				cout << "*";
			cout << '\n';
		}
		for (int i = 0; i <= n / 2; ++i) {
			for (int j = 0; j < i; ++j)
				cout << " ";
			for (int j = n / 2 - i; j >= 0; --j)
				cout << "*";
			cout << '\n';
		}
	}
	else if (m == 3) {
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < i; ++j)
				cout << ' ';
			for (int j = 0; j < n - 2 * i; ++j)
				cout << "*";
			cout << '\n';
		}
		for (int i = 0; i <= n / 2; ++i) {
			for (int j = n / 2 - i; j > 0; --j)
				cout << ' ';
			for (int j = 0; j < 2 * i + 1; ++j)
				cout << "*";
			cout << '\n';
		}
	}
	else if (m == 4) {
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < i; ++j)
				cout << ' ';
			for (int j = 0; j <= n/2 - i; ++j)
				cout << "*";
			cout << '\n';
		}
		for (int i = 0; i <= n / 2; ++i) {
			for (int j = 0; j < n/2; ++j)
				cout << ' ';
			for (int j = 0; j < i + 1; ++j)
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

	if (n >= 1 && n <= 100 && n% 2 != 0 && m >= 1 && m <= 4)
		solution(n, m);
	else
		cout << "INPUT ERROR!";
	return 0;
}