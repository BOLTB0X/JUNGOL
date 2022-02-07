#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int adj[501][501];
int check[501];
int visited[501];

//깊이우선탐색
void DFS(int n, int m, int oj, int cur) {
	if (oj != cur) {
		check[oj]++;
		check[cur]++;
	}

	visited[cur] = 1;
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 0 && adj[cur][i] != 0) 
			DFS(n, m, oj, i);
	}
	return;
}

int solution(int n, int m) {
	int answer = 0;

	for (int i = 1; i <= n; ++i) {
		//방문리스트 초기화
		memset(visited, 0, sizeof(int) * (n + 1));
		//일단 자기 자신들로 호출
		DFS(n, m, i, i);
	}

	for (int i = 1; i <= n; ++i) {
		//해당 노드의 카운트가 n-1이어야 자신의 등수를 알 수 있음
		if (check[i] == n - 1)
			answer++;
	}

	return answer;
}

int main(void) {
	int n, m, from, to;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &from, &to);
		adj[from][to] = 1; //작은 놈
	}

	int ret = solution(n, m);

	printf("%d", ret);
	return 0;
}