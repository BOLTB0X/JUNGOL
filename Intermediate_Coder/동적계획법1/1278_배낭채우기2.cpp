#include <iostream>
#include <vector>

using namespace std;

// 최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n, int w, vector<int>& wis, vector<int>& pis) {
	int answer = 0;
	// dp테이블 초기화
	vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

	// 보텀업 방식
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= w; ++j) {
			dp[i][j] = dp[i - 1][j];

			// 제한선 내라면
			if (j - wis[i] >= 0) 
				dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - wis[i]] + pis[i]);
		}
	}

	answer = dp[n][w];
	return answer;
}


int main(void) {
	// 초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, w; // 갯수, 배낭 용량
	int wi, pi; // 보석의 무게, 값어치
	vector<int> wis, pis;

	cin >> n >> w;
	wis.resize(n + 1);
	pis.resize(n + 1);

	for (int i = 1; i <= n; ++i) 
		cin >> wis[i] >> pis[i];

	int ret = solution(n, w, wis, pis);
	cout << ret;

	return 0;
}
