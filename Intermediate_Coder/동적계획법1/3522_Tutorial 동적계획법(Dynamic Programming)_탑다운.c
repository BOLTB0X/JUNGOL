#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 시간초과
// 탑다운 방식 -> 재귀
int fibo_recur(int n) {
	if (n == 1 || n == 2)
		return 1;
	return fibo_recur(n - 1) + fibo_recur(n - 2);
}

int main(void) {
	int n, result;
	scanf("%d", &n);
	
	result = fibo_recur(n); 

	printf("%d", result% 1000000007);

	return 0;
}
