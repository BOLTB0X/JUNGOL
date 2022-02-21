#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ML 501

int adj[ML][ML];
int visited[ML];
int dist[ML];

//DFS로 탐색
void DFS(int n, int cur, int oj) {
	if (cur != oj) {
		dist[cur]++;
		dist[oj]++;
	}

	visited[cur] = 1;
	for (int i = 1; i <= n; ++i) {
		if (adj[cur][i] == 0)
			continue;
		if (visited[i] == 1)
			continue;
		DFS(n, i, oj);
	}
	return;
}

int solution(int n, int m) {
	int answer = 0;

	//거리, 방문리스트 초기화
	for (int i = 0; i <= n; ++i) {
		dist[i] = 0;
		visited[i] = 0;
	}

	//각 노드를 시작으로 거리리스트에 방문횟수 저장
	for (int i = 1; i <= n; ++i) {
		DFS(n, i, i);
		//방문리스트 초기화
		for (int i = 0; i <= n; ++i)
			visited[i] = 0;
	}
	
	//자기 자신을 제외하고 등수 비교가 가능하는 경우는 dist -> n-1인경우
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
