#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int adj[501][501];
int visited[501];
int dist[501];

void DFS(int n, int cur, int oj) {
	if (cur != oj) {
		dist[cur]++;
		dist[oj]++;
	}

	visited[cur] = 1;
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 0 && adj[cur][i] == 1) 
			DFS(n, i, oj);
	}
	return;
}

int solution(int n, int m) {
	int answer = 0;
	memset(dist, 0, sizeof(int) * (n + 1));

	for (int i = 1; i <= n; ++i) {
		memset(visited, 0, sizeof(int) * (n + 1));
		DFS(n, i, i);
	}

	for (int i = 1; i <= n; ++i) {
		if (dist[i] == n - 1)
			answer++;
	}

	return answer;
}

int main(void) {
	int n, m, from, to;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &from, &to);
		adj[from][to] = 1;
	}

	int ret = solution(n, m);

	printf("%d", ret);
	return 0;
}
