#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; //방, 문
vector<vector<int>> graph; //무향 그래프
vector<bool> visited; //방문리스트
vector<int> answer;

//깊이우선탐색
void DFS(int start) {
	visited[start] = true;
	answer.push_back(start);
	for (int next : graph[start]) {
		if (visited[next])
			continue;
		DFS(next);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	graph.resize(n + 1);
	visited.resize(n + 1, false);
	
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	//정렬
	for (int i = 1; i <= n; ++i) 
		sort(graph[i].begin(), graph[i].end());

	//DFS 시작
	DFS(1);
	
	//출력
	for (int a : answer)
		cout << a << ' ';
	cout << '\n';

	return 0;
}
