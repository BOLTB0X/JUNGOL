#include <iostream>
#include <vector>

using namespace std;

vector<int> per;

void dice(int n, int m, int level) {
	if (level == n) {
		int tot = 0;
		for (int i = 0; i < n; ++i)
			tot += per[i];

		if (tot == m) {
			for (int i = 0; i < n; ++i)
				cout << per[i] << ' ';
			cout << '\n';
		}
		return;
	}

	for (int i = 1; i <= 6; ++i) {
		per.push_back(i);
		dice(n, m, level + 1);
		per.pop_back();
	}
	return;
}

void solution(int n, int m) {
	dice(n, m, 0);
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	solution(n, m);

	return 0;
}