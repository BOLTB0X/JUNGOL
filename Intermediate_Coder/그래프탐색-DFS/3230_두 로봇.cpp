#include <iostream>
#include <vector>
#define ML 100001

using namespace std;

int n, result, robot1, robot2, flag = 0;
vector<pair<int,int>> adj[ML];
vector<bool> visited;

//ÃÖ´ñ°ª ¹ÝÈ¯
int max(int a, int b) {
	return a > b ? a : b;
}


//±íÀÌ¿ì¼±Å½»öÀ¸·Î ÁøÇà
void DFS(int cur, int tot, int cur_dist) {
	visited[cur] = 1;

	if (flag)
		return;

	if (cur == robot2) {
		result = tot - cur_dist;
		flag = 1;
		return;
	}

	for (auto& next : adj[cur]) {
		if (visited[next.first])
			continue;
		visited[next.first] = 1;
		DFS(next.first, tot + next.second, max(cur_dist, next.second));
	}
	return;
}

void solution(void) {
	visited.resize(n + 1, false);

	//Å½»ö
	DFS(robot1, 0, 0);
	return;
}

int main(void) {
	//ÃÊ±âÈ­
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

	solution();

	cout << result;
	return 0;
}