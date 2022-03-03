#include <iostream>
#include <vector>
#include <cstring>
#define ML 100001 //최대 사이즈

using namespace std;

int cnt, r_cnt;
vector<int> adj[ML]; //큰 놈들 -> 최악의 등수를 알 수 있음
vector<int> r_adj[ML]; // 작은 놈들 -> 최고의 등수를 알 수 있음
int visited[ML];

//기준 보다 큰 애들
void Lower(int cur) {
	if (visited[cur] == 1)
		return;

	visited[cur] = 1;
	cnt++;

	for (int& next : adj[cur]) 
		Lower(next);
	return;
}

//기준보다 작은 애들 
void Higher(int cur) {
	if (visited[cur] == 1)
		return;

	visited[cur] = 1;
	r_cnt++;

	for (int& next : r_adj[cur]) 
		Higher(next);
	return;
}

pair<int, int> solution(int n, int m, int x) {
	pair<int, int> answer;
	cnt = 0;
	memset(visited, 0, sizeof(int) * n + 1); //방문리스트 초기화
	Lower(x);
	
	r_cnt = 0;
	memset(visited, 0, sizeof(int) * n + 1); //방문리스트 초기화
	Higher(x);

	answer.first = r_cnt;
	answer.second = n - cnt + 1;
	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		r_adj[b].push_back(a);
	}

	pair<int, int> ret = solution(n, m, x);
	cout << ret.first << ' ' << ret.second;
	return 0;
}
