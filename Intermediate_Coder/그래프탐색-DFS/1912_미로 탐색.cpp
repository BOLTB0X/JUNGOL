#include <iostream>
#include <vector>
#include <algorithm>
#define MS 100001 #최대 길이

using namespace std;

vector<int> adj[MS];

//깊이우선탐색 
void DFS(int n, vector<int>& visited, int cur, vector<int>& path) {
	path.push_back(cur);
	visited[cur] = 1; //재방문

	for (int& next : adj[cur]) {
		//재방문 
		if (visited[next] == 1)
			continue;

		//다시 호출
		DFS(n, visited, next, path);
	}
	return;

}

void solution(int n, int m) {
	vector<int> answer;
	vector<int> visited(n + 1, 0);

	//정렬 - > 작은 수부터 진행하는 게
	for (int i = 1; i <= n; ++i)
		sort(adj[i].begin(), adj[i].end());

	//깊이우선 탐색으로 탐색 시작
	DFS(n, visited, 1, answer);

	for (int& a : answer)
		cout << a << ' ';

	return;
}

int main(void) {
	int n, m;
	int a, b;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	solution(n, m);

	return 0;
}
