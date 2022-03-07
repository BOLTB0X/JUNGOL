#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<int>& v, int start, int mid, int end) {
	int* sorted = new int[end - start + 1];
	int i, j, k; //i->v , k-> sored

	i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		if (v[i] <= v[j])
			sorted[k++] = v[i++];
		else
			sorted[k++] = v[j++];
	}

	if (i > mid) 
		while(j <= end) sorted[k++] = v[j++];
	
	else 
		while (i <= mid) sorted[k++] = v[i++];
	
	for (i = start, k = 0; i <= end; ++i, ++k)
		v[i] = sorted[k];

	delete[] sorted;
	return;
}

// 분할을 재귀적으로 호출
void merge_Sort(vector<int>& v, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_Sort(v, start, mid);
		merge_Sort(v, mid + 1, end);
		merge(v, start, mid, end);
	}

	return;
}

int result;
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

//깊이우선탐색
void DFS(vector<vector<int>>& board, vector<vector<int>>& visited, int n, int y, int x) {
	result++; //카운트
	visited[y][x] = 1;

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		if (visited[ny][nx] == 1)
			continue;
		if (board[ny][nx] == 0)
			continue;

		DFS(board, visited, n, ny, nx);
	}
	return;
}

vector<int> solution(int n, vector<vector<int>>& board) {
	vector<int> answer;
	//방문리스트
	vector<vector<int>> visited(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			//아파트를 발견하면
			if (board[i][j] == 1 && visited[i][j] == 0) {
				result = 0;
				DFS(board, visited, n, i, j);
				answer.push_back(result);
			}
	}

	merge_Sort(answer, 0, answer.size() - 1); //병합정렬

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<vector<int>> board;
	string tmp;

	cin >> n;
	board.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < n; ++j)
			board[i][j] = (tmp[j] - '0');
	}

	vector<int> ret = solution(n, board);

	cout << ret.size() << '\n';
	for (int& r : ret)
		cout << r << '\n';

	return 0;
}