#include <iostream>
#include <vector>
#define Max_Size 100001

using namespace std;

int cnt, r_cnt;
vector<int> adj[Max_Size]; // 나보다 큰
vector<int> radj[Max_Size]; // 작은
vector<int> visited(Max_Size, 0);

void Higher(int n, int cur) {
	visited[cur] = 1;
	r_cnt++;

	for (int& next : radj[cur]) {
		if (visited[next] == 1)
			continue;
		Higher(n, next);
	}
	return;
}

void Lower(int n, int cur) {
	visited[cur] = 1;
	cnt++;

	for (int& next : adj[cur]) {
		if (visited[next] == 1)
			continue;
		Lower(n, next);
	}
	return;
}

vector<int> solution(int n, int m, int x) {
	vector<int> answer(2, 0);
	cnt = 0, r_cnt = 0;

	Higher(n, x);
	visited = vector<int>(Max_Size, 0);
	Lower(n, x);

	answer[0] = r_cnt;
	answer[1] = n - cnt + 1;

	return answer;
}

int main(void) {
	int n, m, x;
	int a, b;

	cin >> n >> m >> x;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;

		adj[a].push_back(b);
		radj[b].push_back(a);
	}

	vector<int> ret = solution(n, m, x);
	cout << ret[0] << ' ' << ret[1];
	return 0;
}
