#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur(int n, int level) {
	if (n == 1) 
		return level;
	
	if (n % 2 == 0)
		recur(n / 2, level + 1);
	else if (n % 2 != 0)
		recur(n / 3, level + 1);
}

void solution(void) {
	long long n;
	scanf("%lld", &n);


	printf("%d", recur(n, 0));
	return;
}

int main(void) {
	solution();
	return 0;
}