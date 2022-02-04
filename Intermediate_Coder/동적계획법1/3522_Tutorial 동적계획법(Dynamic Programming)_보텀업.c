#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[100001] = { 0, };

int main(void) {
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 1;

	//º¸ÅÓ¾÷
	for (int i = 3; i <= n; ++i)
		dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000007);

	printf("%d", dp[n]);

	return 0;
}