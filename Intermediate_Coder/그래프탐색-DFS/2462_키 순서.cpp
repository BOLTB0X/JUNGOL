#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool adj[501][501];

void func(void) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (adj[j][i] && adj[i][k])
					adj[j][k] = 1;
			}
		}
	}

	return;
}

int solution(void) {
	int answer = 0;

	func(); //플로이드

	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (adj[i][j] || adj[j][i])
				cnt++;
		}
		if (cnt == n - 1)
			answer++;
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a][b] = 1;
	}

	int ret = solution();
	cout << ret;
	
	return 0;
}