#include <iostream>
#include <vector>
#include <algorithm>
#define MLN 100001

using namespace std;

int n, m;
vector<int> adj[MLN]; //무향 그래프
vector<int> answer; //정답
vector<bool> visited(MLN, false); //방문

void DFS(int cur) {
	answer.push_back(cur);
	visited[cur] = true;

	for (int& next : adj[cur]) {
		if (!visited[next])
			DFS(next);
	}
	return;
}

void solution(void) {
	//한 번도 들르지 않은 방이 있다면 그 중 가장 번호가 작은 방
	for (int i = 1; i <= n; ++i)
		sort(adj[i].begin(), adj[i].end());

	DFS(1);

	for (int& a : answer) 
		cout << a << ' ';
	cout << '\n';

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	solution();

	return 0;
}
