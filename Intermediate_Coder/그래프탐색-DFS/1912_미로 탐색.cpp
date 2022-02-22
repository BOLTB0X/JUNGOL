#include <iostream>
#include <vector>
#include <algorithm>
#define ML 3001

using namespace std;

vector<int> adj[ML];

//깊이우선 탐색
void DFS(int n, vector<bool>& visited,int start) {
	visited[start] = 1;
	cout << start << ' ';

	for (int& next : adj[start]) {
		if (visited[next])
			continue;
		DFS(n, visited, next);
	}

	return;
}

void solution(int n, int m) {
	vector<bool> visited(n + 1, false);

	DFS(n, visited, 1);
	return;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		sort(adj[a].begin(), adj[a].end());
		sort(adj[b].begin(), adj[b].end());
	}

	solution(n, m);
	return 0;
}
