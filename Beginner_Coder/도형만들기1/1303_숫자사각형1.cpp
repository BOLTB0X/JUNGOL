#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int number = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << number++ << ' ';
		}
		cout << "\n";
	}
	return  0;
}