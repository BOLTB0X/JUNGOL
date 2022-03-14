#include <iostream>
#include <vector>

using namespace std;

//최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n, int w, vector<pair<int, int>>& arr) {
	int answer = 0;
	//dp 테이블 초기화
	vector<int> dp(w + 1, 0);
	vector<int> wi(n + 1, 0); //각 보석의 무게
	vector<int> pi(n + 1, 0); //각 보석의 값어치

	for (int i = 0; i < n;++i) {
		wi[i + 1] = arr[i].first;
		pi[i + 1] = arr[i].second;
	}

	//보텀업
	for (int i = 1; i <= n; ++i) {
		//현재 보석으러만 채워보면서
		//최댓값으로 교체
		for (int j = 1; j <= w; ++j) {
			//제한선 내이면
			if (j - wi[i] >= 0) 
				dp[j] = Max(dp[j], dp[j - wi[i]] + pi[i]);
		}
	}

	answer = dp[w];
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, w;
	vector<pair<int, int>> arr;
	cin >> n >> w;

	for (int i = 0; i < n; ++i) {
		int a, b;

		cin >> a >> b;
		arr.push_back({ a,b });
	}

	int ret = solution(n, w, arr);
	cout << ret;

	return 0;
}
