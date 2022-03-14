#include <iostream>

using namespace std;

int steps[301];
int dp[301] = { 0, };

//최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> steps[i];

	dp[1] = steps[1];
	dp[2] = steps[1] + steps[2];
	dp[3] = Max(steps[1] + steps[3], steps[2] + steps[3]);

	//보텀업 
	for (int i = 4; i <= n; ++i) 
		dp[i] = steps[i] + Max(dp[i - 3] + steps[i - 1], dp[i - 2]);
	
	cout << dp[n];
	return 0;
}
