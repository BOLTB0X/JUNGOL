#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[5];
	int target,i, j, weight;
	int answer = 0;

	for (i = 0; i < 5; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &target);

	for (i = 4, weight = 16; i >= 0; --i, weight /= 2) {
		for (j = 1; j <= arr[i]; ++j) {
			if (weight * j == target) {
				answer += j;
				printf("%d", answer);
				return 0;
			}
			//�ʰ��� ���
			else if (weight * j > target) {
				answer += (j - 1);
				target -= (weight * (j - 1));
				break; //�� ���Դ� �� �̻� ��� �Ҵ�
			}
		}
		if (j == arr[i] + 1) {
			answer += (j - 1);
			target -= weight * (j - 1);
		}
	}
	printf("impossible");
	return 0;
}