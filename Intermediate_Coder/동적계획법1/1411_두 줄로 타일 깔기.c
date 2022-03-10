#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[100001] = { 0, };
const int mod = 20100529;

void solution(int n) {
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; ++i) 
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % mod;
	
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);

	solution(n);

	printf("%d\n", dp[n]);
	return 0;
}
