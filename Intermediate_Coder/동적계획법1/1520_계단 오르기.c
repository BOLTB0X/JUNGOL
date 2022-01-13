#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int my_max(int a, int b) {
	return a > b ? a : b;
}

void solution(void) {
	int n;
	scanf("%d", &n);
	int* dp = malloc(sizeof(int) * (n + 1));
	int* steps = malloc(sizeof(int) * (n + 1));
	
	for (int i = 1; i <= n; ++i)
		scanf("%d", &steps[i]);

	dp[1] = steps[1];
	dp[2] = steps[1]+steps[2];
	dp[3] = my_max(steps[3] + steps[1], steps[2] + steps[3]);


	//º¸ÅÒ¾÷
	for (int i = 4; i <= n; ++i) {
		dp[i] = my_max(dp[i - 3] + steps[i - 1] + steps[i], dp[i - 2] + steps[i]);
	}

	printf("%d", dp[n]);

	free(dp);
	free(steps);
}

int main(void) {
	solution();
	return 0;
}