#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr_idx, target;
int arr[11];
int dp[64001];

void solution(void) {	
	for (int i = 1; i <= target; ++i)
		dp[i] = target + 1;

	//�ܵ� 1���� target����
	//���Ҿ�
	for (int i = 1; i <= target; ++i) {
		for (int j = 1; j <= arr_idx; ++j) {
			//�ܵ��� ������ ���ٸ�
			if (i == arr[j]) {
				dp[i] = 1;
				break;
			}
			//�ܵ� - ������ 0���� ũ�� ���� dp������ �۴ٸ�
			if (i - arr[j] > 0 && dp[i] > dp[i - arr[j]] + 1)
				dp[i] = dp[i - arr[j]] + 1;
		}
	}

	if (dp[target] != target + 1)
		printf("%d", dp[target]);
	else
		printf("impossible");
	return;
}

int main(void) {
	scanf("%d", &arr_idx);

	for (int i = 1; i <= arr_idx; ++i)
		scanf("%d", &arr[i]);

	scanf("%d", &target);

	solution();
	return 0;
}