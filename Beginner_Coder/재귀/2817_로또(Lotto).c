#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int numbers[14];
int com[14];
int visited[14] = { 0, };

//조합
void DFS(int n, int level, int cur) {
	if (level == 6) {
		for (int i = 0; i < 6; ++i)
			printf("%d ", com[i]);
		printf("\n");
		return;
	}

	for (int i = cur; i < n; ++i) {
		if (visited[i])
			continue;
		com[level] = numbers[i];
		visited[i] = 1;
		DFS(n, level + 1, i);
		visited[i] = 0;
	}
	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &numbers[i]);
	
	
	DFS(n, 0, 0);

	return;
}
int main(void) {
	solution();

	return 0;
}
