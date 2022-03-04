#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int coins_type[7];
int cost[7] = {0, 500, 100, 50, 10, 5, 1 }; //동전의 가치
int cnt[7];

int MIN(int a, int  b) {
	return a < b ? a : b;
}

void solution(int n, int tot) {
	int result = 0;
	//동전의 최대 개수를 구해야 하므로
	//작은 동전 타입부터 그리디 알고리즘 방식으로 진행해야함
	for (int i = 0; i < 7; ++i)
		cnt[i] = 0;

	n = tot - n; //남은 돈으로 변환

	//각 동전 사용을 최소로 카운트 배열 구함
	for (int i = 1; i <= 6; ++i) {
		int tmp = MIN(coins_type[i], n / cost[i]);
		n -= (cost[i] * tmp);
		cnt[i] += tmp;
	}
	
	//총 갯수 
	for (int i = 1; i <= 6; ++i) 
		result += (coins_type[i] - cnt[i]);
	
	printf("%d\n", result);
	for (int i = 1; i <= 6; ++i)
		printf("%d ", coins_type[i] - cnt[i]);
	return;
}

int main(void) {
	int n, tot = 0;
	scanf("%d", &n);
	for (int i = 1; i <= 6; ++i) {
		scanf("%d", &coins_type[i]);
		tot += (coins_type[i] * cost[i]);
	}

	solution(n, tot);

	return 0;
}
