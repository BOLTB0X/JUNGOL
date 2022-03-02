#include <iostream>
#include <vector>
#define ML 100001

using namespace std;

typedef struct {
	int vertex, dist;
} Node;

int result = 0x7fffffff; // 최솟값을 위한
vector<Node> adj[ML];
vector<int> visited;

int MIN(int a, int b) {
	return a < b ? a : b;
}

//깊이우선탐색으로 거리의 합의 최솟값을 구함
void DFS(int n, int cur, int target, int tot, int max_dist) {
	//탈출 조건
	if (cur == target) {
		result = MIN(result, tot - max_dist);
		return;
	}

	visited[cur] = 1;

	//노드를 탐색
	for (Node& next : adj[cur]) {
		//재방문
		if (visited[next.vertex] == 1)
			continue;

		visited[next.vertex] = 1;
		int nd = next.dist > max_dist ? next.dist : max_dist;
		//탐색
		DFS(n, next.vertex, target, tot + next.dist, nd);
	}
	return;
}

int solution(int n, int robot1, int robot2) {
	int answer = 0;

	//방문리스트 초기화
	visited.resize(n + 1, 0);
	DFS(n, robot1, robot2, 0, 0);

	answer = result;
	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, robot1, robot2;
	int a, b, c;
	cin >> n >> robot1 >> robot2;

	//무향
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	int ret = solution(n, robot1, robot2);

	cout << ret;
	return 0;
}
