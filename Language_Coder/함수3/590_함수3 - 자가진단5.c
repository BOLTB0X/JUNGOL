#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int per[101];

void DFS(int n, int level) {
	if (level > n) {
		for (int i = 1; i <= n; ++i) 
			printf("%d ", per[i]);
		printf("\n");
		return;
	}

	for (int i = per[level - 1]; i <= 6; ++i) {
		per[level] = i;
		DFS(n, level + 1);
	}

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	per[0] = 1;
	DFS(n, 1);
	return;
}

int main(void) {
	solution();

	return 0;
}