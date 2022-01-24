#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[100001] = { 0, };

void solution(void) {
	int n;
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; ++i) 
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 20100529;
	
	printf("%d\n", dp[n]);
	return;
}

int main(void) {
	solution();
	return 0;
}