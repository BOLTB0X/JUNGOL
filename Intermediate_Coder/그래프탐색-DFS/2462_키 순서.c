#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ML 501

int adj[ML][ML];
int visited[ML];
int cnt[ML];

//방문리스트 초기화
void init(int n) {
	for (int i = 1; i <= n; ++i) 
		visited[i] = 0;
	return;
}

//깊이우선 탐색으로 카운팅
void DFS(int n, int m, int student, int compare_student) {
	//카운트 조건
	if (student != compare_student) {
		cnt[student]++;
		cnt[compare_student]++;
	}

	visited[student] = 1; //방문처리
	for (int i = 1; i <= n; ++i) {
		//재방문
		if (visited[i] == 1)
			continue;

		//비교 학생이 없다면
		if (adj[student][i] == 0)
			continue;

		//비교 학생 바꾸어 다시 탐색
		DFS(n, m, i, compare_student);
	}
	return;
}

int solution(int n, int m) {
	int answer = 0;
	init(n);
	
	//카운트 배열 초기화
	for (int i = 1; i <= n; ++i)
		cnt[i] = 0;

	for (int i = 1; i <= n; ++i) {
		DFS(n, m, i, i); //비교 학생 i를 고정으로 각 탐색
		init(n); //탐색 후 방문리스트 초기화
	}

	for (int i = 1; i <= n; ++i) {
		//자기 등수를 알 수 있는 것은
		if (cnt[i] == n - 1) //자기 자신을 제외한 n - 1
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
