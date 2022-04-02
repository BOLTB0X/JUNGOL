#include <iostream>

using namespace std;

void solution(int n, int m) {
	if (m == 1) {
		int number = 0, tmp;

		for (int i = 1; i <= n; ++i) {
			if (i % 2 == 0) {
				number += i;
				tmp = number;

				for (int j = 1; j <= i; ++j)
					cout << tmp-- << ' ';
			}
			else {
				number++;
				for (int j = 1; j <= i; ++j)
					cout << number++ << ' ';
				number--; // 증감되어 넘어가므로
			}
			cout << '\n';
		}
	}
	else if (m == 2) {
		int number = 0, tmp = 2 * n - 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < 2 * i - 1; ++j)
				cout << " ";
			for (int j = 1; j <= tmp; ++j)
				cout << number << " ";
			cout << "\n";
			number++;
			tmp -= 2;
		}
	}
	
	else if (m == 3) {
		for (int i = 1; i <= n / 2 + 1; ++i) {
			int number = 1;
			for (int j = 1; j <= i; ++j)
				cout << number++ << ' ';
			cout << '\n';
		}
		for (int i = n / 2; i > 0; --i) {
			int number = 1;
			for (int j = 1; j <= i; ++j)
				cout << number++ << ' ';
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

	if (n >= 1 && n <= 100 && n % 2 != 0 && m>=1 && m <= 3)
		solution(n, m);
	else
		cout << "INPUT ERROR!";
	return 0;
}
