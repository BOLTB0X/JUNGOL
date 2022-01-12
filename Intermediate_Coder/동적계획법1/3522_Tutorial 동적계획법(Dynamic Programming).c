#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//탑다운
int fibo_recur(int n) {
	if (n == 1 || n == 2)
		return 1;
	return fibo_recur(n - 1) + fibo_recur(n - 2);
}

void solution(void) {
	int fibo[100001];
	fibo[1] = fibo[2] = 1;
	
	int n;
	scanf("%d", &n);

	//보텀업
	for (int i = 3; i <= n; ++i)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000007;
		

	printf("%d", fibo[n]);
	//printf("%d", fibo_recur(n));
	return;
}

int main(void) {
	solution();
	return 0;
}