#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> coins;

void solution(int n, int target) {
	//잔돈 1부터 target까지
	//보텀업 방식
	for (int i = 1; i <= target; ++i) {
		//현재 타겟을 코인들로 거스러 줄 수 있는지
		for (int j = 1; j <= n; ++j) {
			//i과 동전이 같다면
			if (i == coins[j]) {
				dp[i] = 1;
				break;
			}
			//타겟 - 동전이 0보다 크고 기존 dp값보다 작다면
			if (i - coins[j] > 0 && dp[i] > dp[i - coins[j]])
				dp[i] = dp[i - coins[j]] + 1;
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, target;
	cin >> n;

	coins.resize(n + 1, 0);
	
	for (int i = 1; i <= n; ++i)
		cin >> coins[i];
	cin >> target;
	dp.resize(target + 1, target + 1);

	
	solution(n, target);
	
	if (dp[target] != target + 1)
		cout << dp[target];
	else
		cout << "impossible";
	return 0;
}
