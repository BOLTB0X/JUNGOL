#include <iostream>
using namespace std;

int dp[41][41];
int cmm[41];

int solution(int n, int m) {
	int answer = 0;

	//√ ±‚»≠
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <=n; ++j)
			dp[i][j] = 0;
	}
	
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= n; ++i) {
		if (cmm[i] == 1 || cmm[i - 1] == 1)
			dp[i][i - 1] = 0;
		else
			dp[i][i - 1] = dp[i - 1][i - 1];

		dp[i][i] = dp[i - 1][i - 1] + dp[i - 1][i - 2];
	}

	answer = dp[n][n] + dp[n][n - 1];
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int idx;
		cin >> idx;
		cmm[idx] = 1;
	}
	
	int ret = solution(n, m);
	cout << ret;
	return 0;
}