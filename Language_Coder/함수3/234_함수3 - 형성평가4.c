#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[102] = { 0, };
int arr_idx = 3;

int recur(int n) {
	if (n < arr_idx)
		return arr[n];
	arr[arr_idx++] = (arr[arr_idx - 1] * arr[arr_idx - 2]) % 100;
	recur(n);
}

void solution(void) {
	int n;
	scanf("%d", &n);

	arr[1] = 1;
	arr[2] = 2;

	printf("%d", recur(n));
	return;
}

int main(void) {
	solution();
	return 0;
}
