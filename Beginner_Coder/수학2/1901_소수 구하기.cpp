#include <iostream>

using namespace std;

int is_prime(int number) {
	if (number == 0 || number == 1)
		return 0;
	for (int i = 2; i * i <= number; ++i) {
		if (number % i == 0)
			return 0;
	}
	return 1;
}

void get_prime(int number) {
	int flag = 0;

	if (is_prime(number)) {
		cout << number << '\n';
		return;
	}

	for (int i = 1; !flag; ++i) {
		if (is_prime(number - i)) {
			flag = 1;
			cout << number - i << ' ';
		}

		if (is_prime(number + i)) {
			flag = 1;
			cout << number + i << ' ';
		}
		cout << '\n';
	}

	return;
}

void solution(int n) {
	int numb;
	for (int i = 0; i < n; ++i) {
		cin >> numb;
		get_prime(numb);
	}

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