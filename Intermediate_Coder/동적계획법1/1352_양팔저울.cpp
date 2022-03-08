#include <iostream>
#include <vector>

using namespace std;

int dp[35][40005];

//절댓값반환
int Abs(int a) {
	return a < 0 ? -a : a;
}

void solution(int n, int m, vector<int>& weights, vector<int>& beads) {
	//dp테이블 초기화
	vector<int> tot(n + 1, 0);

	//합계 벡터
	for (int i = 1; i <= n; ++i) 
		tot[i] = tot[i - 1] + weights[i];
	
	//보텀업
	for (int i = 1; i <= n; ++i) {
		//현재 무게는 측정가능
		dp[i][weights[i]] = 1;

		//계산 가능했던 무게마다, 이번 추를 증가, 감소, 미사용
		for (int j = 1; j <= tot[i - 1]; ++j) {
			if (dp[i - 1][j] == 1) {
				dp[i][j] = 1;
				dp[i][j + weights[i]] = 1; //반대쪽 이용
				dp[i][Abs(j - weights[i])] = 1; //현재 추를 측정 무게와 같이
			}
		}
	}

	for (int i = 1; i <= m; ++i) {
		if (dp[n][beads[i]] == 1)
			cout << 'Y' << ' ';
		else
			cout << 'N' << ' ';
	}
	
	return ;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> weights, beads;

	cin >> n;
	weights.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> weights[i];

	cin >> m;
	beads.resize(m + 1, 0);
	for (int i = 1; i <= m; ++i)
		cin >> beads[i];

	solution(n, m, weights, beads);
	
	return 0;
}