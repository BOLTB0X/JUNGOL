#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> coins;

int min(int a, int b) {
	return a < b ? a : b;
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

	
	//�ܵ� 1���� target����
	//���Ҿ�
	for (int i = 1; i <= target; ++i) {
		//���� Ÿ���� ���ε�� �Ž��� �� �ִ��� Ȯ��
		for (int j = 1; j <= n; ++j) {
			//�ܵ��� ������ ���ٸ�
			if (i == coins[j]) {
				dp[i] = 1;
				break;
			}
			//�ܵ� - ������ 0���� ũ�� ���� dp������ �۴ٸ�
			if (i - coins[j] > 0 && dp[i] > dp[i - coins[j]] + 1)
				dp[i] = dp[i - coins[j]] + 1;
		}
	}
	
	if (dp[target] != target + 1)
		cout << dp[target];
	else
		cout << "impossible";
	return 0;
}