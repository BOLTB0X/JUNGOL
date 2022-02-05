#include <iostream>
#include <vector>

using namespace std;

int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution(vector<pair<int, int>>& bag, int n, int w) {
	int answer = 0;
	//dp 테이블 초기화
	vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= w; ++j) {
			dp[i][j] = dp[i - 1][j];

			if (bag[i].first <= j)
				dp[i][j] = MAX(dp[i - 1][j - bag[i].first] + bag[i].second, dp[i - 1][j]);
		}
	}
	
	answer = dp[n][w];
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, w; //갯수, 배낭 용량
	int wi, pi; // 보석의 무게, 값어치
	vector<pair<int, int>> bag; //가방

	cin >> n >> w;
	bag.resize(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> wi >> pi;
		bag[i].first = wi;
		bag[i].second = pi;
	}

	int ret = solution(bag, n, w);
	cout << ret;

	return 0;
}