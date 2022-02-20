#include <iostream>

using namespace std;

void factorial(int n, long long result) {
	if (n == 1) {
		cout << "1! = 1\n";
		cout << result << '\n';
		return;
	}
	cout << n << "! = " << n << " * " << n - 1 << "!\n";
	factorial(n - 1, result * n);
	return;
}

void solution(int n) {
	//재귀 이용
	factorial(n, 1);
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	solution(n);
	return 0;
}