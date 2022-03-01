#include <iostream>
#include <vector>
#define ML 100001

using namespace std;

typedef struct {
	int next, dist;
} Node;

int result, flag = 0;
vector<Node> adj[ML];
vector<int> visited;

void DFS(int n, int cur, int target, int tot, int max_dist) {
	//도달 햇는데 진행 할 경우
	if (flag == 1)
		return;

	//도착지에 도달했다면
	if (cur == target) {
		result = tot - max_dist; //최대 간선의 길이를 뺀다
		flag = 1;
		return;
	}

	visited[cur] = 1; //방문처리

	//탐색
	for (Node& next : adj[cur]) {
		//재방문인 경우
		if (visited[next.next] == 1)
			continue;

		visited[next.next] = 1;
		int nd = next.dist > max_dist ? next.dist : max_dist;
		DFS(n,next.next, target, tot + next.dist, nd);
	}

	return;
}

int solution(int n, int robot1, int robot2) {
	int answer = 0;
	result = 0;
	//초기화
	visited.resize(n + 1, 0);

	//탐색
	DFS(n, robot1,robot2, 0, 0);

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
