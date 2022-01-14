#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[10001];
int inf[10001][2];

int max(int a, int b) {
	return a >= b ? a : b;
}

int Top_down(int n, int w) {
	int tmp;

	for (int i = 1; i <= n; ++i) {
		for (int j = inf[i][0]; j <= w; ++j) {
			//규칙성
			tmp = dp[j - inf[i][0]] + inf[i][1];

			dp[j] = max(dp[j], tmp);
		}
	}

	return dp[w];
}

void solution(void) {
	int n, w;
	scanf("%d %d", &n, &w);

	for (int i = 1; i <= n; ++i)
		scanf("%d %d", &inf[i][0], &inf[i][1]);
	
	printf("%d", Top_down(n, w));
	return;
}

int main(void) {
	solution();
	return 0;
}
