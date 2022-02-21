#include <iostream>
#include <vector>

using namespace std;

vector<int> tmp;
vector<vector<int>> com;

//동일한 배열인지 체크
bool is_same_Arr(vector<int>& cmp, vector<int>& v) {
	int size = v.size();
	for (int i = 0; i < size; ++i) {
		if (cmp[i] != v[i])
			return false;
	}
	return true;
}

//조합
void combination(int n, int k, vector<bool>& visited, int cur, int level) {
	if (level == k) {
		com.push_back(tmp);
		return;
	}

	for (int i = cur; i < n; ++i) {
		if (visited[i])
			continue;
		visited[i] = true;
		tmp.push_back(i + 1);
		combination(n, k, visited, i + 1, level + 1);
		tmp.pop_back();
		visited[i] = false;
	}
	return;
}

void solution(int n, int k, vector<int>& v) {
	int target_idx = -1;
	vector<bool> visited(n, false);
	
	//조합 생성
	combination(n, k, visited, 0, 0);

	//같은 조합이 있는 지 체크
	for (int i = 0; i < com.size();++i) {
		if (is_same_Arr(com[i], v)) {
			target_idx = i;
			break;
		}
	}

	if (target_idx == com.size() - 1 || target_idx == -1)
		cout << "NONE";
	else {
		for (int& c : com[target_idx + 1])
			cout << c << ' ';
	}
	return;
}

int main(void) {
	//초기화
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
