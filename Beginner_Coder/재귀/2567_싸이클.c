#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void recur(int *arr, int n, int p, int number) {
	if (arr[number] == 2) 
		return;
	arr[number]++;
	recur(arr, n, p, (number * n) % p);
	return;
}

int solution(int *arr, int n, int p) {
	int cycle = 0;
	recur(arr, n, p, n);

	for (int i = 0; i < p; ++i) {
		if (arr[i] == 2)
			cycle++;
	}

	return cycle;
}

int main(void) {
	int n, p;
	int arr[10001] = { 0, };

	scanf("%d %d", &n, &p);

	int ret = solution(arr, n, p);

	printf("%d", ret);
	return 0;
}