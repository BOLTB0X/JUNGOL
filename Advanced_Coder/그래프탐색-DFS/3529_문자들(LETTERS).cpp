#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max_cnt;
//중복 방지용
int alp_cnt[26];
//상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//초기화
void init(int R, int C, vector<vector<int>>& visited) {
	visited.resize(R, vector<int>(C, 0));

	for (int i = 0; i < 26; ++i)
		alp_cnt[i] = 0;

	max_cnt = 0;
	return;
}

//현재 방문 알파벳 갯수 체크 
void count_Alp_cnt(void) {
	int cnt = 0;

	for (int i = 0; i < 26; ++i) {
		if (alp_cnt[i] == 1)
			cnt++;
	}

	if (max_cnt < cnt)
		max_cnt = cnt;

	return;
}

void DFS(int R, int C, vector<string>& board, vector<vector<int>>& visited, int y, int x) {
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		//1번
		if (ny < 0 || nx < 0 || ny >= R || nx >= C)
			continue;

		//2번 조건 
		if (visited[ny][nx] == 1)
			continue;
		
		//3번-> 중복 방지를 위해
		if (alp_cnt[board[ny][nx] - 'A'] == 1)
			continue;

		visited[ny][nx] = 1;
		alp_cnt[board[ny][nx] - 'A'] = 1;
		DFS(R, C, board, visited, ny, nx);
		visited[ny][nx] = 0;
		alp_cnt[board[ny][nx] - 'A'] = 0;
	}
	//여기까지 왔으면 알파벳 갯수 체크
	count_Alp_cnt();
	return;
}

int solution(int R, int C, vector<string>& board) {
	int answer = 0;
	vector<vector<int>> visited; //방문리스트
	
	init(R, C, visited); //매 탐색시 초기화
	visited[0][0] = 1;
	alp_cnt[board[0][0] - 'A'] = 1; //해당 알파벳 방문 체크
	DFS(R, C, board, visited, 0, 0); //해당 위치에서 탐색 시작
	
	answer = max_cnt;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int R, C;
	vector<string> board;

	cin >> R >> C;
	board.resize(R);
	for (int i = 0; i < R; ++i)
		cin >> board[i];

	int ret = solution(R, C, board);
	cout << ret;

	return 0;
}