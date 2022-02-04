#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Å¾´Ù¿î
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