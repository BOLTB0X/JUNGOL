#include <iostream>

using namespace std;

void print_result(int n) {
	int reverse_number = 0;
	int tot = 0;

	while (n > 0) {
		int r = n % 10;
		reverse_number = reverse_number * 10 + r;
		tot += r;

		n /= 10;
	}
	//출력
	cout << reverse_number << ' ' << tot << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(1) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		print_result(n);
		
	}

	return 0;
}
