#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000

using namespace std;

int result;
int adj[51][51];

//플로이드 와샬 알고리즘
void floyd(int n, vector<int>& v) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++)
				adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
		}
	}

	result = INF;
	for (int i = 1; i <= n; ++i) {
		int tmp = 0;
		for (int j = 1; j <= n; ++j)
			tmp = max(tmp, adj[i][j]);

		//최소비용
		if (tmp < result) {
			v.clear();
			result = tmp;
			v.push_back(i);
		}

		else if (tmp == result)
			v.push_back(i);
	}

	return;
}

vector<int> solution(int n) {
	vector<int> answer;

	floyd(n, answer); //플로이드
	//정렬
	sort(answer.begin(), answer.end());

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, a, b;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) adj[i][j] = 0;
			else adj[i][j] = INF;
		}
	}

	while (1) {
		cin >> a >> b;
		if (a == - 1 || b == -1)
			break;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	vector<int> ret = solution(n);
	cout << result << " " << ret.size() << '\n';
	for (int& r : ret)
		cout << r << ' ';
	return 0;
}