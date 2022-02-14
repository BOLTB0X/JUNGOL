#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int coins_type[7];
int cost[7] = {0, 500, 100, 50, 10, 5, 1 };
int cnt[7];

int min(int a, int  b) {
	return a < b ? a : b;
}

void solution(int n, int tot) {
	int result = 0;
	//동전의 최대 개수를 구해야 하므로
	//작은 동전 타입부터 그리디 알고리즘 방식으로 진행해야함
	memset(cnt, 0, sizeof(int) * 7);

	n = tot - n;

	for (int i = 1; i <= 6; ++i) {
		int tmp = min(coins_type[i], n / cost[i]);
		n -= cost[i] * tmp;
		cnt[i] += tmp;
	}
	
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
		tot += coins_type[i] * cost[i];
	}

	solution(n, tot);

	return 0;
}