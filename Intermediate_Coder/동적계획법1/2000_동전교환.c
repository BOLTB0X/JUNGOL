#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int solution(int n, int target, int* coin_type) {
	int answer = 0;
	int* dp;

	dp = (int*)malloc(sizeof(int) * (target + 1)); //dp테이블
	for (int i = 0; i <= target; ++i)
		dp[i] = target + 1; //최솟값을 위한 초기화

	//보텀업 방식
	for (int i = 1; i <= target; ++i) {
		//i가 총 금액이라 가정
		for (int j = 1; j <= n; ++j) {
			//총 금액과 해당 동전 가치가 같다면
			if (i == coin_type[j]) {
				dp[i] = 1;
				break;
			}

			//거슬러 줄수 있고 기존 보다 더 작다면
			if (i > coin_type[j] && dp[i] > dp[i - coin_type[j]] + 1)
				dp[i] = dp[i - coin_type[j]] + 1;
		}
	}

	if (dp[target] != target + 1)
		answer = dp[target];
	else
		answer = -1;

	return answer;
}

int main(void) {
	int n, target;
	int *coin_type;

	scanf("%d", &n);
	coin_type = (int*)malloc(sizeof(int) * (n + 1));

	for (int i = 1; i <= n; ++i)
		scanf("%d", &coin_type[i]);
	scanf("%d", &target);

	int ret = solution(n, target, coin_type);
	if (ret == -1)
		printf("impossible");
	else
		printf("%d", ret);
	return 0;
}
