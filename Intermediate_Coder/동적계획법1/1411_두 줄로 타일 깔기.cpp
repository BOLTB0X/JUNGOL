#include <iostream>

using namespace std;

int dp[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	//���Ҿ�
	for (int i = 3; i <= n; ++i) 
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 20100529;
	
	cout << dp[n];
	return 0;
}