#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cheese_cnt = 0;
int last_cnt = 0;

int n, m;
int board[101][101];
int visited[101][101];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

void init(void) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			visited[i][j] = 0;
	}
	return;
}

int in_Range(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}

//���̿켱Ž������ ���Ⱑ �� ġ�� �� ��� ġ� üũ
void DFS(int y, int x) {
	//ġ�� �߰� �����ڸ��� �쿩���ؼ� Ż��
	if (board[y][x] == 1) {
		cheese_cnt--;
		board[y][x] = 0; //ġ�� ����
		visited[y][x] = 1;
		return;
	}

	//ġ� �ƴϰ� �̹湮�� ���
	else if (visited[y][x] == 0) {
		visited[y][x] = 1;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (visited[ny][nx] == 1)
				continue;

			DFS(ny, nx);
		}
	}
	return;
}

int solution(void) {
	int answer = 0;

	while (cheese_cnt != 0) {
		//�湮����Ʈ �ʱ�ȭ
		init();

		//���
		last_cnt = cheese_cnt;

		//ġ� ���� �����ڸ�����
		DFS(0, 0);
		answer++; //ī��Ʈ
	}
	return answer;
}

int main(void) {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &board[i][j]);
			//ġ�� ī��Ʈ
			if (board[i][j] == 1)
				cheese_cnt++;
		}
	}

	int ret = solution();
	printf("%d\n", ret);
	printf("%d", last_cnt);
	return 0;
}