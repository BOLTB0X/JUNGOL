#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n, flag = 0, result = 0x7fffffff;
int board[14][14];
int visited[14];

void check(int cur, int tot) {
	//마지막 돌아가는 비용이 0이 아니고 기존 비용보다 더 작다면
	if (board[cur][1] != 0 && tot + board[cur][1] < result) {
		flag = 1;
		result = tot + board[cur][1];
	}
	return;
}

void DFS(int cur, int level, int tot) {
	if (level == n) {
		check(cur, tot);
		return;
	}

	for (int i = 2; i <= n; ++i) {
		//재방문
		if (visited[i] == 1)
			continue;
		//이동불가, 즉 i -> i는 0은 탐색 할 필요가 없음
		if (board[cur][i] == 0)
			continue;
		//큰 경우
		if (tot + board[cur][i] > result)
			continue;
		visited[i] = 1;
		DFS(i, level + 1, tot + board[cur][i]);
		visited[i] = 0;
	}

	return;
}

void solution(void) {
	//방문리스트 초기화
	memset(visited, 0, sizeof(int) * 14);
	//백트래킹 시작
	DFS(1, 1, 0);

	return;
}

int main(void) {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			scanf("%d", &board[i][j]);
	}

	solution();

	if (flag == 0)
		result = 0;

	printf("%d", result);
	return 0;
}