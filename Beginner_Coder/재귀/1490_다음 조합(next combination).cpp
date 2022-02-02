#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> com;

void DFS(int n, int k, vector<int>& numbers, vector<bool>& visited, vector<int>& tmp, int cur, int level) {
	if (level == k) {
		com.push_back(tmp);
		return;
	}
	for (int i = cur; i < n; ++i) {
		if (visited[i])
			continue;
		tmp.push_back(numbers[i]);
		visited[i] = 1;
		DFS(n, k, numbers, visited, tmp, i + 1, level + 1);
		tmp.pop_back();
		visited[i] = 0;
	}

	return;
}

void solution(int n, int k, vector<int>& v) {
	vector<int> numbers;
	vector<int> tmp_com;
	vector<bool> visited;

	for (int i = 0; i < n; ++i)
		numbers.push_back(i + 1);
	visited.resize(n, false);

	//먼저 조합 생성
	DFS(n, k, numbers, visited, tmp_com, 0, 0);
	int target = -1;

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
	if (target != -1) {
		for (int i = 0; i < k; ++i) 
			cout << com[target][i] << ' ';
		cout << '\n';
	}
	else {
		cout << "NONE";
	}

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
	for (int i = 0; i < k; ++i)
		cin >> v[i];

	solution(n, k, v);

	return 0;
}