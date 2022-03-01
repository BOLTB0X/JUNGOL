#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//최댓값 반환
int MAX(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer = 0;
	int* dp = malloc(sizeof(int) * (n + 1));
	int* steps = malloc(sizeof(int) * (n + 1));
	
	for (int i = 1; i <= n; ++i)
		scanf("%d", &steps[i]);

	dp[1] = steps[1];
	dp[2] = steps[1] + steps[2];
	dp[3] = MAX(steps[3] + steps[1], steps[2] + steps[3]);

	//보텀업 방식
	//현재 계단을 뭐로 더할지가 관건
	for (int i = 4; i <= n; ++i)
		dp[i] = steps[i] + MAX(dp[i - 3] + steps[i - 1], dp[i - 2]);

	answer = dp[n];

	free(dp);
	free(steps);

	return answer;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int ret = solution(n);

	printf("%d", ret);
	return 0;
}
