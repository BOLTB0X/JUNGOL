#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lotto[13];
int vistied[13];

void DFS(int n, int* arr, int level, int cur) {
	if (level == 6) {
		for (int i = 0; i < 6; ++i) {
			printf("%d ", lotto[i]);
		}
		printf("\n");
		return;
	}

	for (int i = cur; i < n; ++i) {
		if (vistied[i] == 1)
			continue;
		lotto[level] = arr[i];
		vistied[i] = 1;
		DFS(n, arr, level + 1, i + 1);
		vistied[i] = 0;
	}

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);
	int* nums = malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &nums[i]);

	memset(vistied, 0, n * sizeof(int));

	DFS(n, nums, 0, 0);
	free(nums);
	return;
}

int main(void) {
	solution();
	return 0;
}