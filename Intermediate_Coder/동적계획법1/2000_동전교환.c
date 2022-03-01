#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr_idx, target;
int arr[11];
int dp[64001];

int solution(void) {
	int answer = 0;
	//dp 테이블 최댓값 초기화
	for (int i = 1; i <= target; ++i)
		dp[i] = target + 1;
	
	//보텀업
	for (int i = 1; i <= target; ++i) {
		for (int j = 1; j <= arr_idx; ++j) {
			//동전이 같다면
			if (i == arr[j]) {
				dp[i] = 1;
				break;
			}

			//현재 동전 종류보다 크고 기존 dp테이블보다 크다면
			if (i > arr[j] && dp[i] > dp[i - arr[j]] + 1)
				dp[i] = dp[i - arr[j]] + 1;
		}
	}

	if (dp[target] != target + 1)
		answer = dp[target];
	else
		answer = -1;

	return answer;
}

int main(void) {
	scanf("%d", &arr_idx);

	for (int i = 1; i <= arr_idx; ++i)
		scanf("%d", &arr[i]);

	scanf("%d", &target);

	int ret = solution();

	if (ret != -1)
		printf("%d", ret);
	else
		printf("impossible");
	return 0;
}
