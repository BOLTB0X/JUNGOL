#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n, flag = 0, result = 0x7fffffff;
int board[14][14];
int visited[14];

//DFS로 백트래킹
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

		//이동불가
		//장소 사이에 이동할 수 있는 방법이 없다면 비용을 0으로 표시
		if (board[cur][i] == 0)
			continue;

		//진행하기 너무 큰 경우 -> 최소 비용을 구해애함
		if (tot + board[cur][i] > result)
			continue;

		visited[i] = 1;
		DFS(i, level + 1, tot + board[cur][i]);
		visited[i] = 0;
	}
	
	return;
}

int solution(void) {
	int answer = 0;
	//방문리스트 초기화
	memset(visited, 0, sizeof(int) * 14);
	//백트래킹 시작
	DFS(1, 1, 0);

	answer = result;
	return answer;
}

int main(void) {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			scanf("%d", &board[i][j]);
	}

	int ret = solution();

	//도달하지 못한 경우
	if (flag == 0)
		ret = 0;

	printf("%d", ret);
	return 0;
}
