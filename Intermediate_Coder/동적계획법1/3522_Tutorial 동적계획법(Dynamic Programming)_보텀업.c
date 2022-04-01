#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 보텀업 -> 반복문
int do_dynamic(int n) {
	int* dp = malloc(sizeof(int) * n);
	dp[0] = dp[1] = 1;

	for (int i = 2; i < n; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;

	int ret = dp[n - 1];
	free(dp);
	return ret;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int ret = do_dynamic(n);
	printf("%d", ret);
	return 0;
}
