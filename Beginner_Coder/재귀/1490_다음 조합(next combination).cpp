#include <iostream>
#include <vector>

using namespace std;

vector<int> tmp;
vector<vector<int>> com;

void DFS(int n, int k, vector<bool>& visited, int cur, int level) {
	if (level == k) {
		com.push_back(tmp);
		return;
	}

	for (int i = cur; i < n; ++i) {
		if (visited[i])
			continue;
		tmp.push_back(i + 1);
		visited[i] = true;
		DFS(n, k, visited, i + 1, level + 1);
		visited[i] = false;
		tmp.pop_back();
	}
	return;
}

void solution(int n, int k, vector<int>& v) {
	int target = -1;
	vector<bool> visited(n, false);

	DFS(n, k, visited, 0, 0);

	for (int i = 0; i < com.size(); ++i) {
		bool flag = 1;
		for (int j = 0; j < k; ++j) {
			if (com[i][j] != v[j])
				flag = 0;
		}
		if (flag && i != com.size() - 1) {
			target = i + 1;
			break;
		}
	}

	//다음 조합이 존재 하면
	if (target != -1) {
		for (int i = 0; i < k; ++i)
			cout << com[target][i] << ' ';
		cout << '\n';
	}
	else 
		cout << "NONE";
	
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	vector<int> v;

	cin >> n >> k;
	v.resize(k, 0);

	for (int &x: v)
		cin >> x;

	solution(n, k, v);

	return 0;
}
