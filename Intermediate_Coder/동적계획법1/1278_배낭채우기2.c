#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution(int n, int w, int* wi, int* pi) {
	int answer = 0;
	//dp 태이블 초기화
	int** dp;
	dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; ++i) {
		dp[i] = (int*)malloc(sizeof(int) * (w + 1));
		memset(dp[i], 0, sizeof(int) * (w + 1));
	}

	//보텀업
	for (int i = 1; i <= n; ++i) {
		//제한선을 1부터 w까지 진행하는 보텀업 방식
		for (int j = 1; j <= w; ++j) {
			dp[i][j] = dp[i - 1][j];

			//제한 선을 넘지 않는 다면
			if (wi[i] <= j) //첫만남 시 p[i]가 dp[i][j], 여유가 되면 더해지고 vs dp[i-1][j -1] 비교
				dp[i][j] = MAX(dp[i - 1][j - wi[i]] + pi[i], dp[i - 1][j - 1]);
		}
	}
	
	answer = dp[n][w];
	
	free(dp[0]);
	free(dp);
	return answer;
}

int main(void) {
	int n, w;
	int *wi, *pi;

	scanf("%d %d", &n, &w);
	wi = (int*)malloc(sizeof(int) * (n + 1));
	pi = (int*)malloc(sizeof(int) * (n + 1));
	wi[0] = pi[0] = 0;

	for (int i = 1; i <= n; ++i)
		scanf("%d %d", &wi[i], &pi[i]);

	int ret = solution(n, w, wi, pi);
	printf("%d", ret);

	free(wi);
	free(pi);
	return 0;
}
