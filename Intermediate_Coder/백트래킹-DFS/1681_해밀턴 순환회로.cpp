#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, result = 0x7fffffff;
int board[14][14];
bool visited[14];

void DFS(int cur, int level, int tot) {
	if (level >= n) {
		//다시 1로 돌아오는 것이므로
		if (board[cur][1] != 0 && result > tot + board[cur][1])
			result = tot + board[cur][1];
		return;
	}

	for (int i = 2; i <= n; ++i) {
		if (visited[i] || board[cur][i] == 0)
			continue;
		if (tot + board[cur][i] > result)
			continue;
		visited[i] = 1;
		DFS(i, level + 1, tot + board[cur][i]);
		visited[i] = 0;
	}
	return;
}

void solution(void) {
	memset(visited, false, sizeof(bool) * 14);
	DFS(1, 1, 0);

	return;
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> board[i][j];
	}

	solution();

	cout << result;
	return 0;
}