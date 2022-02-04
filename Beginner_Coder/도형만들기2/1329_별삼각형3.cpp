#include <iostream>

using namespace std;

void solution(int n) {
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < i; ++j)
			cout << " ";
		for (int j = 0; j <= 2*i; ++j)
			cout << "*";
		cout << '\n';
	}
	for (int i = 0; i <= n / 2; ++i) {
		for (int j = n / 2 - i; j > 0; --j)
			cout << " ";
		for (int j = 0; j < n - 2 * i; ++j)
			cout << "*";
		cout << '\n';
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n >= 1 && n <= 100 && n % 2 != 0)
		solution(n);
	else
		cout << "INPUT ERROR!";
	return 0;
}