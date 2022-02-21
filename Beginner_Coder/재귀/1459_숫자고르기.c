#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int result;

//����Ŭ �Ǻ�
void cycle(int* arr, int* cnt, int n, int cur, int target) {
	// �Է� ���� �̿��ϸ�
	// 1���� �����ϴ� ����Ŭ �Ѱ�, 
	// 3���� �����ϴ� ����Ŭ �Ѱ�, 
	// 5���� �����ϴ� ����Ŭ �Ѱ�.
	for (int i = 1; i <= n; ++i) {
		if (cur == target) {
			result++;
			cnt[cur] = 1;
			return;
		}
		//���Ҹ� ������
		cur = arr[cur];
	}

	return;
}

void solution(int n, int* arr, int* cnt) {
	result = 0;
	for (int i = 1; i <= n; ++i)
		cycle(arr, cnt, n, arr[i], i);

	printf("%d\n", result);
	for (int i = 1; i <= n; ++i) {
		if (cnt[i])
			printf("%d\n", i);
	}

	return;
}

int main(void) {
	int n, cards[101] = { 0, }, cnt[101];

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &cards[i]);
		cnt[i] = 0;
	}

	solution(n, cards, cnt);
	return 0;
}