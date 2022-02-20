#include <iostream>
#include <vector>

using namespace std;

vector<int> com;

//백트래킹 이용
void DFS(int n, vector<int>& numbers, vector<bool>& visited, int cur, int level) {
	if (level == 6) {
		for (int& c : com)
			cout << c << ' ';
		cout << '\n';
		return;
	}

	for (int i = cur; i < n; ++i) {
		if (visited[i])
			continue;
		com.push_back(numbers[i]);
		visited[i] = true;
		DFS(n, numbers, visited, i + 1, level + 1);
		visited[i] = false;
		com.pop_back();
	}

	return;
}

void solution(int n, vector<int>& numbers) {
	vector<bool> visited(n, false);

	DFS(n, numbers, visited, 0, 0);
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<int> numbers;

	cin >> n;
	numbers.resize(n);
	for (int& num : numbers)
		cin >> num;

	solution(n, numbers);
	return 0;
}
