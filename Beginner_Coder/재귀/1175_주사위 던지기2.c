#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[7];

//눈의 합이 맞는지 체크
int check(int n, int m) {
	int tot = 0;
	for (int i = 0; i < n; ++i)
		tot += arr[i];

	return tot == m ? 1 : 0;
}

void print_arr(int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	return;
}

//중복순열 
void DFS(int n, int m, int level) {
	//탈출 조건
	if (level == n) {
		if (check(n, m))
			print_arr(n);
		return;
	}

	for (int i = 0; i < 6; ++i) {
		arr[level] = (i + 1);
		DFS(n, m, level + 1);
	}
}

void solution(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	DFS(n, m, 0);
	return;
}

int main(void) {
	solution();
	return 0;
}
