#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> coins;

void solution(int n, int target) {
	dp.resize(target + 1, target + 1); //최솟값을 위해 최댓값 셋팅

	//보텀업
	//잔돈 1부터 target까지
	for (int i = 1; i <= target; ++i) {
		//현재 타겟을 코인들로 거스러 줄 수 있는지
		for (int j = 1; j <= n; ++j) {
			//타겟과 동전의 가치가 같다면
			if (i == coins[j]) {
				dp[i] = 1; //1
				break;
			}

			//최소 갯수를 구해야하므로
			if (i - coins[j] > 0 && dp[i] > dp[i - coins[j]] + 1)
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
