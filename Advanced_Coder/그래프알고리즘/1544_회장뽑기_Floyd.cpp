#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int result;
int adj[51][51];

void floyd(int n, vector<int>& v) {
	for (int k = 1; k <= n; ++k) {
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n; ++b)
				adj[a][b] = min(adj[a][b], adj[a][k] + adj[k][b]);
		}
	}

	result = INF;
	
	for (int i = 1; i <= n; ++i) {
		int tmp = 0;
		for (int j = 1; j <= n; ++j)
			tmp = max(tmp, adj[i][j]);

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

	floyd(n, answer);

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) adj[i][j] = 0;
			else adj[i][j] = INF;
		}
	}

	while (1) {
		int a, b;
		cin >> a >> b;

		if (a == -1 || b == -1)
			break;

		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	vector<int> ret = solution(n);
	cout << result << " " << ret.size() << '\n';
	sort(ret.begin(), ret.end());
	for (int& r : ret)
		cout << r << ' ';
	return 0;

}
