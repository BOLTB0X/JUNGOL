#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int nums[7] = { 0, };
int visited[6] = { 0, };

void dice1(int n, int m, int level) {
	if (level == n) {
		for (int i = 0; i < n; ++i) 
			printf("%d ", nums[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= 6; ++i) {
		nums[level] = i;
		dice1(n, m, level + 1);
	}

	return;
}


void dice2(int n, int m, int level) {
	if (level > n) {
		for (int i = 1; i <= n; ++i) 
			printf("%d ", nums[i]);
		printf("\n");
		return;
	}

	for (int i = nums[level-1]; i <= 6; ++i) {
		nums[level] = i;
		dice2(n, m, level + 1);
	}

	return;
}

void dice3(int n, int m, int level) {
	if (level == n) {
		for (int i = 0; i < n; ++i) 
			printf("%d ", nums[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < 6; ++i) {
		if (visited[i] == 1)
			continue;
		nums[level] = i + 1;
		visited[i] = 1;
		dice3(n, m, level + 1);
		visited[i] = 0;
	}

	return;
}

void solution(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	if (m == 1)
		dice1(n, m, 0);
	else if (m == 2) {
		nums[0] = 1;
		dice2(n, m, 1);
	}

	else if (m == 3)
		dice3(n, m, 0);
	return;
}

int main(void) {
	solution();
	return 0;
}