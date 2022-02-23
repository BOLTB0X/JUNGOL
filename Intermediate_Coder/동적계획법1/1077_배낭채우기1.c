#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[10001];
int inf[10001][2];

//최댓값반환
int MAX(int a, int b) {
	return a >= b ? a : b;
}

void solution(int n, int w) {
	for (int i = 1; i <= w; ++i)
		dp[i] = 0;
	//보텀업
	//n번 반복해야함
	for (int i = 1; i <= n; ++i) {
		//현재 보석의 무게 부터 데드드라인까지 보텀업 방식
		for (int j = inf[i][0]; j <= w; ++j) {
			//dp테이블에 해당 무게값을 누적으로 더해줌 -> 중복 허용이므로
			int tmp = dp[j - inf[i][0]] + inf[i][1]; 
			dp[j] = MAX(dp[j], tmp);
		}
	}
	
	printf("%d", dp[w]);
	return;
}

int main(void) {
	int n, w;
	scanf("%d %d", &n, &w);

	for (int i = 1; i <= n; ++i)
		scanf("%d %d", &inf[i][0], &inf[i][1]);
	solution(n, w);
	return 0;
}
