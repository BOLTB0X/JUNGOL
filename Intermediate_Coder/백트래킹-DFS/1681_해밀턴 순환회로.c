#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, flag = 0, result = 2e9;
int board[14][14];
int visited[14];

//백트래킹을 위한 DFS
void DFS(int cur, int level, int tot) {
	if (level == n) {
		//마지막 돌아가는 곳이 0이 아니고 기존 비용보다 더 작다면
		if (board[cur][1] != 0 && tot + board[cur][1] < result) {
			flag = 1;
			result = tot + board[cur][1];
		}
		return;
	}

	for (int i = 2; i <= n; ++i) {
		//재방문
		if (visited[i] == 1)
			continue;

		//자기 자신이므로
		if (board[cur][i] == 0)
			continue;

		//진행하기 너무 큰 경우 -> 최소 비용을 구해애함
		if (tot + board[cur][i] > result)
			continue;

		visited[i] = 1;
		DFS(i, level + 1, tot + board[cur][i]);
		visited[i] = 0; //백트래킹
	}
	return;
}

int solution(void) {
	int answer = 0;

	//초기화
	for (int i = 1; i <= n; ++i) 
		visited[i] = 0;
	
	//백트래킹 시작
	DFS(1, 1, 0);

	//도달 했다면
	if (flag == 1)
		answer = result;

	return answer; //반환
}

int main(void) {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			scanf("%d", &board[i][j]);
	}

	int ret = solution();

	printf("%d", ret);
	return 0;
}
