#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int MAX(int a, int b) {
	return a > b ? a : b;
}

void solution(void) {
	int n;
	scanf("%d", &n);
	int* dp = malloc(sizeof(int) * (n + 1));
	int* steps = malloc(sizeof(int) * (n + 1));
	
	for (int i = 1; i <= n; ++i)
		scanf("%d", &steps[i]);

	dp[1] = steps[1];
	dp[2] = steps[1]+steps[2];
	dp[3] = MAX(steps[3] + steps[1], steps[2] + steps[3]);


	//보텀업
	//바로 전 칸을 밟을 지 말지 결정
	for (int i = 4; i <= n; ++i) {
		dp[i] = steps[i] + MAX(dp[i -3] + steps[i - 1], dp[i - 2]);
	}

	printf("%d", dp[n]);

	free(dp);
	free(steps);
}

int main(void) {
	solution();
	return 0;
}
