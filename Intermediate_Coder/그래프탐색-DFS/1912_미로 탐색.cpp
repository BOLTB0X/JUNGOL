#include <iostream>
#include <vector>
#include <algorithm>
#define Max_Size 100001 // 최대 길이

using namespace std;

vector<int> adj[Max_Size]; // 인접리스트

// 깊이우선탐색
void DFS(int n, vector<int>& visited, vector<int>& path, int cur) {
	visited[cur] = 1;
	path.push_back(cur); // 삽입

	// 오름차순으로 다음 노드들이 정렬되어 있으므로
	for (int& next : adj[cur]) {
		// 재방문
		if (visited[next] == 1)
			continue;

		// 호출
		DFS(n, visited, path, next);
	}

	return;
}

vector<int> solution(int n, int m) {
	vector<int> answer;

	vector<int> visited(n + 1, 0); // 방문리스트
	
	// 한 번도 들르지 않은 방이 있다면 그 중 가장 번호가 작은 방으로 가고
	// 정렬해줘야함
	for (int i = 1; i <= n; ++i)
		sort(adj[i].begin(), adj[i].end());

	DFS(n, visited, answer, 1);

	return answer;
}

int main(void) {
	int n, m, a, b;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> ret = solution(n, m);
	for (int& r : ret)
		cout << r << ' ';

	return 0;
}
