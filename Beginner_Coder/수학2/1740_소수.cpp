#include <iostream>
#define ML 10001

using namespace std;

int check[ML] = { 0, };

void solution(int m, int n) {
	check[0] = check[1] = 1;
	for (int i = 2; i * i < ML; ++i) {
		if (check[i] == 1)
			continue;
		for (int j = i + i; j < ML; j += i)
			check[j] = 1;
	}

	int flag = 0, min_value, tot = 0;

	for (int i = m; i <= n; ++i) {
		if (check[i] == 0) {
			if (flag == 0) {
				flag = 1;
				min_value = i;
			}
			tot += i;
		}
	}
	if (flag == 1) {
		cout << tot << '\n';
		cout << min_value;
	}
	else
		cout << -1;
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	solution(m, n);

	return 0;
}