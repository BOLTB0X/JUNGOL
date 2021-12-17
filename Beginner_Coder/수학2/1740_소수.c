#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int arr[10001];

int is_prime(int n) {
	if (n == 1 || n == 0)
		return 0;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int get_arr_sum() {
	int idx = 0;
	int tot = 0;

	while (arr[idx] != -1) 
		tot += arr[idx++];
	
	return tot;
}

void solution(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(arr, -1, sizeof(int) * (m - n + 1));

	int idx = -1;
	for (int i = n; i <= m; ++i) {
		if (is_prime(i)) 
			arr[++idx] = i;
	}

	if (idx == -1) 
		printf("-1\n");

	else {
		printf("%d\n", get_arr_sum());
		printf("%d\n", arr[0]);
	}

	return;
}

int main(void) {
	solution();
	return 0;
}