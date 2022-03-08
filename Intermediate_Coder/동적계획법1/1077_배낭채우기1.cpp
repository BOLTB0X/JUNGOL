#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int w, vector<pair<int, int>>& inf) {
	int answer = 0;
	//dp테이블 초기화
	vector<int> dp(w + 1, 0);

	//보텀업 방식
	for (int i = 1; i <= n; ++i) {
		//해당 i번 가방내 중복허용하고 dp테이블을 채움
		for (int j = inf[i].first; j <= w; ++j) {
			//제한선 내 인경우
			if (j >= inf[i].first) {
				int tmp = dp[j - inf[i].first] + inf[i].second;
				dp[j] = tmp > dp[j] ? tmp : dp[j];
			}
		}
	}

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, w; //보석 가지 수, 최대 용량
	vector<pair<int, int>> inf; //무게와 값어치

	cin >> n >> w;
	inf.resize(n + 1);

	for (int i = 1; i <= n; ++i) 
		cin >> inf[i].first >> inf[i].second;

	int ret = solution(n, w, inf);
	cout << ret;
	
	return 0;
}
