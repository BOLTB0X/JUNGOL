#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(1) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		int tot1 = 0;
		int tot2 = 0;

		while (n > 0) {
			int r = n % 10;
			tot1 = tot1 * 10 + r;
			tot2 += r;
			n /= 10;
		}

		cout << tot1 << ' ' << tot2 << '\n';
	}

	return 0;
}