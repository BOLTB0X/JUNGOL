#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int result;

//사이클 판별
void cycle(int* arr, int* cnt, int n, int cur, int target) {
	// 입력 예를 이용하면
	// 1에서 시작하는 사이클 한개, 
	// 3에서 시작하는 사이클 한개, 
	// 5에서 시작하는 사이클 한개.
	for (int i = 1; i <= n; ++i) {
		if (cur == target) {
			result++;
			cnt[cur] = 1;
			return;
		}
		//원소를 맟춰줌
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