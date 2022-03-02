#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ML 501

int adj[ML][ML];
int visited[ML];
int cnt[ML];

void init(int n) {
	for (int i = 1; i <= n; ++i) 
		visited[i] = 0;
	return;
}

//깊이 우선 탐색으로 object 기준으로 키 비교
void DFS(int n, int m, int student, int object) {
	//카운트 기준
	if (student != object) {
		cnt[student]++;
		cnt[object]++;
	}

	visited[student] = 1;
	for (int i = 1; i <= n; ++i) {
		//비교할 학생이 없다면
		if (adj[student][i] == 0)
			continue;
		//재방문
		if (visited[i] == 1)
			continue;
		DFS(n, m, i, object);
	}
	return;
}

int solution(int n, int m) {
	int answer = 0;
	
	//방문리스트 및 카운트 초기화
	for (int i = 1; i <= n; ++i) {
		visited[i] = 0;
		cnt[i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		DFS(n, m, i, i);
		init(n); //방문리스트 초기화
	}

	//자기 자신을 제외하고 등수 비교가 가능하는 경우는 dist -> n-1인경우
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == n - 1)
			answer++;
	}

	return answer;
}

int main(void) {
	int n, m, a, b;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		adj[a][b] = 1; // a학생이 b학생보다 키가 작다
	}

	int ret = solution(n, m);

	printf("%d", ret);
	return 0;
}
