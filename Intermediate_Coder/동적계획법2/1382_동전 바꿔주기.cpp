#include <iostream>

using namespace std;

int dp[101][10001];

int solution(int T, int k, pair<int, int>* coin_inf) {
	int answer = 0;

	//dp초기화
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= T; ++j) 
			dp[i][j] = 0;
	}

	dp[0][0] = 1;
	for (int i = 1; i <= k; ++i) {
		int coin_value = coin_inf[i].first;
		int coin_cnt = coin_inf[i].second;
		for (int j = 0; j <= T; ++j) {
			dp[i][j] = dp[i - 1][j];

			for (int k = 1; k <= coin_cnt; ++k) {
				if (j - k * coin_value >= 0)
					dp[i][j] += dp[i - 1][j - k * coin_value];
				else
					break;
			}
		}
	}

	answer = dp[k][T];

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, k;
	pair<int, int> coin_inf[101];

	cin >> T >> k;

	for (int i = 1; i <= k; ++i)
		cin >> coin_inf[i].first >> coin_inf[i].second;

	int ret = solution(T, k, coin_inf);
	cout << ret;

	return 0;
}