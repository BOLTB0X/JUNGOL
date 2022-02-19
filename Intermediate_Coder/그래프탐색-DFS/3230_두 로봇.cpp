#include <iostream>
#include <vector>
#define ML 100001

using namespace std;

int n, result, robot1, robot2, flag = 0;
vector<pair<int,int>> adj[ML];
vector<bool> visited;

//최댓값 반환
int MAX(int a, int b) {
	return a > b ? a : b;
}

//깊이우선탐색으로 진행
void DFS(int cur, int tot, int cur_dist) {
	if (flag)
		return;

	if (cur == robot2) {
		result = tot - cur_dist;
		flag = 1;
		return;
	}

	visited[cur] = 1;
	for (pair<int,int>& next : adj[cur]) {
		if (visited[next.first])
			continue;
		visited[next.first] = 1;
		DFS(next.first, tot + next.second, MAX(cur_dist, next.second));
	}
	return;
}

int solution(void) {
	int answer = 0;
	//초기화
	visited.resize(n + 1, false);

	//탐색
	DFS(robot1, 0, 0);

	answer = result;
	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> n >> robot1 >> robot2;

	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	int ret = solution();

	cout << ret;
	return 0;
}
