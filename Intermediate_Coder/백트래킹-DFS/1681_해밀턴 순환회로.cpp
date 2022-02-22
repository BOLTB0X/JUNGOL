#include <iostream>
#include <vector>

using namespace std;

int result = 0x7fffffff, flag = 0;

void DFS(int n, vector<vector<int>>& board, vector<bool>& visited, int cur, int tot, int level) {
	//탈출 조건
	if (level == n) {
		//돌아가는 비용이 0 아니고 기존 비용보다 작다면
		if (board[cur][1] != 0 && tot + board[cur][1] < result) {
			flag = 1; //비용이 생겼다는 표시
			result = tot + board[cur][1];
		}
		return;
	}

	//1 부터 시작했으니 
	for (int col = 2; col <= n; ++col) {
		//재방문
		if (visited[col])
			continue;
		//이동불가
		if (board[cur][col] == 0)
			continue;
		//최소 비용이므로
		if (tot + board[cur][col] > result)
			continue;
		visited[col] = 1;
		DFS(n, board, visited, col, tot + board[cur][col], level + 1);
		visited[col] = 0;
	}
	return;
}

int solution(int n, vector<vector<int>>& board) {
	int answer = 0;
	vector<bool> visited(n + 1, false);

	//비용은 양방향이 아니라 단방향으로 가기 위한 비용
	DFS(n, board, visited, 1, 0, 1);
	answer = result;
	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<vector<int>> board;

	cin >> n;
	board.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) 
			cin >> board[i][j];
	}

	int ret = solution(n, board);
	//다시 1로 못 돌아가는 경우였다면
	if (flag == 0)
		ret = 0;
	cout << ret;
	return 0;
}
