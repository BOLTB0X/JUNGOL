#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> steps;

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	steps.resize(n + 1, 0);
	dp.resize(n + 1, 0);

	for (int i = 1; i <= n; ++i)
		cin >> steps[i];

	dp[1] = steps[1];
	dp[2] = steps[1] + steps[2];
	dp[3] = max(steps[2] + steps[3], steps[1] + steps[3]);

	//보텀업
	//바로 앞 칸을 밟을지 말지
	for (int i = 4; i <= n; ++i)
		dp[i] = steps[i] + max(dp[i - 3] + steps[i - 1], dp[i - 2]);
	
	cout << dp[n];
	return 0;
}