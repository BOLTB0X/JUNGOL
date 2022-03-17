#include <iostream>
#include <vector>

using namespace std;

//백트래킹 이용
void DFS(int n, vector<int>& numbers, vector<bool>& visited, int cur, int level) {
	if (level == 6) {
		for (int i = 0; i < n; ++i) {
			//방문여부로 출력 가능
			if (visited[i]) 
				cout << numbers[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = cur; i < n; ++i) {
		//재방문
		if (visited[i])
			continue;

		visited[i] = true;
		DFS(n, numbers, visited, i + 1, level + 1);
		visited[i] = false;
	}

	return;
}

void solution(int n, vector<int>& numbers) {
	vector<bool> visited(n, false); //방문리스트

	DFS(n, numbers, visited, 0, 0);
	return;
}

int main(void) {
	//초기화
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
